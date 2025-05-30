#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

using namespace std;

// ======================== EXCEPTION CLASSES ========================
class UniversitySystemException : public exception {
protected:
    string message;
public:
    UniversitySystemException(string msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(string msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(string msg) : UniversitySystemException("Grade Error: " + msg) {}
};

// ========================= PERSON BASE CLASS =========================
class Person {
protected:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person(string n, int a, string id, string c = "") {
        setName(n);
        setAge(a);
        ID = id;
        contact = c;
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << ", Contact: " << contact << endl;
    }

    virtual double calculatePayment() const { return 0.0; }

    void setName(string n) {
        if (n.empty()) throw invalid_argument("Name cannot be empty.");
        name = n;
    }

    void setAge(int a) {
        if (a <= 0 || a > 120) throw invalid_argument("Invalid age.");
        age = a;
    }

    string getID() const { return ID; }
};

// ========================= STUDENT CLASS =========================
class Student : public Person {
private:
    string enrollmentDate;
    string program;
    double GPA;

public:
    Student(string n, int a, string id, string eDate, string prog, double gpa, string c = "")
        : Person(n, a, id, c), enrollmentDate(eDate), program(prog) {
        setGPA(gpa);
    }

    void setGPA(double gpa) {
        if (gpa < 0.0 || gpa > 4.0) throw invalid_argument("Invalid GPA.");
        GPA = gpa;
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate << ", Program: " << program << ", GPA: " << GPA << endl;
    }
};

// ========================= PROFESSOR CLASS =========================
class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;

public:
    Professor(string n, int a, string id, string dept, string spec, string hire, string c = "")
        : Person(n, a, id, c), department(dept), specialization(spec), hireDate(hire) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << ", Specialization: " << specialization << ", Hire Date: " << hireDate << endl;
    }
};

// ========================= COURSE CLASS =========================
class Course {
private:
    string code;
    string title;
    int credits;
    string description;
    Professor* instructor; // Aggregation

public:
    Course(string c, string t, int cr, string desc, Professor* prof)
        : code(c), title(t), credits(cr), description(desc), instructor(prof) {
        if (credits <= 0) throw invalid_argument("Credits must be positive.");
    }

    void displayDetails() const {
        cout << "\nCourse: " << title << " (" << code << "), Credits: " << credits << endl;
        cout << "Description: " << description << endl;
        if (instructor != NULL) {
            cout << "Instructor Info: ";
            instructor->displayDetails();
        }
    }

    string getCode() const { return code; }
};

// ========================= GRADEBOOK CLASS =========================
class GradeBook {
private:
    map<string, double> grades;

public:
    void addGrade(string studentID, double grade) {
        if (grade < 0.0 || grade > 100.0) throw GradeException("Grade must be between 0 and 100.");
        grades[studentID] = grade;
    }

    void displayGrades() const {
        map<string, double>::const_iterator it;
        for (it = grades.begin(); it != grades.end(); ++it) {
            cout << "Student ID: " << it->first << " | Grade: " << it->second << endl;
        }
    }
};

// ===================== ENROLLMENT MANAGER CLASS =====================
class EnrollmentManager {
private:
    map<string, vector<string> > enrollments; // courseCode -> studentIDs

public:
    void enrollStudent(const string& studentID, const string& courseCode) {
        enrollments[courseCode].push_back(studentID);
    }

    void displayEnrollments() const {
        map<string, vector<string> >::const_iterator it;
        for (it = enrollments.begin(); it != enrollments.end(); ++it) {
            cout << "Course: " << it->first << " | Students: ";
            for (size_t i = 0; i < it->second.size(); ++i) {
                cout << it->second[i] << " ";
            }
            cout << endl;
        }
    }
};

// ========================= UNIVERSITY SYSTEM =========================
class UniversitySystem {
private:
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
    EnrollmentManager enrollmentManager;
    GradeBook gradeBook;

public:
    void addStudent(const Student& s) { students.push_back(s); }
    void addProfessor(const Professor& p) { professors.push_back(p); }
    void addCourse(const Course& c) { courses.push_back(c); }

    void enroll(const string& studentID, const string& courseCode) {
        enrollmentManager.enrollStudent(studentID, courseCode);
    }

    void assignGrade(const string& studentID, double grade) {
        gradeBook.addGrade(studentID, grade);
    }

    void showAllCourses() const {
        for (size_t i = 0; i < courses.size(); ++i) {
            courses[i].displayDetails();
        }
    }

    void showAllEnrollments() const {
        enrollmentManager.displayEnrollments();
    }

    void showAllGrades() const {
        gradeBook.displayGrades();
    }
};

// ============================== MAIN MENU ==============================
int main() {
    UniversitySystem university;

    Professor p("Dr. Smith", 50, "P001", "CS", "AI", "2010-08-01");
    university.addProfessor(p);

    Course cs("CS101", "Intro to Programming", 3, "Basics of coding.", &p);
    university.addCourse(cs);

    Student s("Alice", 20, "S001", "2023-09-01", "B.Tech", 3.8);
    university.addStudent(s);

    int choice;
    do {
        cout << "\n===== University Management Menu =====\n";
        cout << "1. Enroll Student in Course\n2. Assign Grade\n3. Show All Courses\n4. Show Enrollments\n5. Show Grades\n0. Exit\nEnter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                string sid, cid;
                cout << "Enter Student ID and Course Code: ";
                cin >> sid >> cid;
                university.enroll(sid, cid);
                cout << "Enrollment successful.\n";
            } else if (choice == 2) {
                string sid;
                double grade;
                cout << "Enter Student ID and Grade: ";
                cin >> sid >> grade;
                university.assignGrade(sid, grade);
                cout << "Grade recorded.\n";
            } else if (choice == 3) {
                university.showAllCourses();
            } else if (choice == 4) {
                university.showAllEnrollments();
            } else if (choice == 5) {
                university.showAllGrades();
            } else if (choice != 0) {
                cout << "Invalid choice.\n";
            }
        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }

    } while (choice != 0);

    cout << "Program terminated.\n";
    return 0;
}
