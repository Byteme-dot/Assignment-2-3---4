#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

// Base Exception Class
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

class PaymentException : public UniversitySystemException {
public:
    PaymentException(string msg) : UniversitySystemException("Payment Error: " + msg) {}
};

// Base Class: Person
class Person {
protected:
    string name;
    int age;
    string ID;
public:
    Person(string n, int a, string id) {
        setName(n);
        setAge(a);
        ID = id;
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << endl;
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
};

// Derived Class: Student
class Student : public Person {
private:
    double GPA;
public:
    Student(string n, int a, string id, double gpa) : Person(n, a, id) {
        setGPA(gpa);
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "GPA: " << GPA << endl;
    }

    void setGPA(double gpa) {
        if (gpa < 0.0 || gpa > 4.0) throw invalid_argument("Invalid GPA.");
        GPA = gpa;
    }
};

// Derived Class: Professor
class Professor : public Person {
private:
    string department;
public:
    Professor(string n, int a, string id, string dept) : Person(n, a, id), department(dept) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << endl;
    }
};

// Class: Course
class Course {
private:
    string code, title;
    int credits;
    Professor* instructor;
public:
    Course(string c, string t, int cr, Professor* prof) : code(c), title(t), credits(cr), instructor(prof) {}

    void displayDetails() const {
        cout << "Course: " << title << " (" << code << "), Credits: " << credits << endl;
        instructor->displayDetails();
    }
};

// Class: GradeBook
class GradeBook {
private:
    map<string, double> grades;
public:
    void addGrade(string studentID, double grade) {
        if (grade < 0 || grade > 100) throw GradeException("Invalid grade.");
        grades[studentID] = grade;
    }

    double calculateAverageGrade() {
        if (grades.empty()) throw GradeException("No grades available.");
        double sum = 0;
        for (auto &entry : grades) sum += entry.second;
        return sum / grades.size();
    }
};

// Class: EnrollmentManager
class EnrollmentManager {
private:
    map<string, vector<string>> enrollments;
public:
    void enrollStudent(string studentID, string courseID) {
        enrollments[courseID].push_back(studentID);
    }

    int getEnrollmentCount(string courseID) {
        return enrollments[courseID].size();
    }
};

// Class: UniversitySystem
class UniversitySystem {
private:
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
public:
    void addStudent(Student s) { students.push_back(s); }
    void addProfessor(Professor p) { professors.push_back(p); }
    void addCourse(Course c) { courses.push_back(c); }

    void displayAllCourses() {
        for (const auto &course : courses) course.displayDetails();
    }
};

// Main Menu
void menu() {
    UniversitySystem university;
    EnrollmentManager enrollment;
    GradeBook gradeBook;

    Professor prof1("Dr. Alice", 45, "P123", "Computer Science");
    university.addProfessor(prof1);

    Course cs101("CS101", "Programming Basics", 3, &prof1);
    university.addCourse(cs101);

    Student student1("Bob", 21, "S456", 3.7);
    university.addStudent(student1);

    int choice;
    do {
        cout << "\nUniversity Management System\n";
        cout << "1. Enroll Student\n2. Add Grade\n3. Display Courses\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                string studentID, courseID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Course ID: ";
                cin >> courseID;
                enrollment.enrollStudent(studentID, courseID);
                cout << "Student enrolled successfully!\n";
            } else if (choice == 2) {
                string studentID;
                double grade;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Grade: ";
                cin >> grade;
                gradeBook.addGrade(studentID, grade);
                cout << "Grade recorded successfully!\n";
            } else if (choice == 3) {
                university.displayAllCourses();
            } else if (choice == 4) {
                cout << "Exiting...\n";
            } else {
                cout << "Invalid choice!\n";
            }
        } catch (const UniversitySystemException &e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}