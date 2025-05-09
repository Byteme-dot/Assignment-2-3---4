#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Base Class: Person
class Person {
protected:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person(string n, int a, string i, string c) : name(n), age(a), ID(i), contact(c) {}

    virtual void displayDetails() {
        cout << "Name: " << name << "\nAge: " << age << "\nID: " << ID << "\nContact: " << contact << endl;
    }

    virtual ~Person() {} // Virtual destructor
};

// Derived Class: Student
class Student : public Person {
private:
    string enrollmentDate, program;
    double GPA;

public:
    Student(string n, int a, string i, string c, string e, string p, double g)
        : Person(n, a, i, c), enrollmentDate(e), program(p), GPA(g) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate << "\nProgram: " << program << "\nGPA: " << GPA << endl;
    }
};

// Derived Class: Professor
class Professor : public Person {
private:
    string department, specialization, hireDate;

public:
    Professor(string n, int a, string i, string c, string d, string s, string h)
        : Person(n, a, i, c), department(d), specialization(s), hireDate(h) {}

    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << department << "\nSpecialization: " << specialization << "\nHire Date: " << hireDate << endl;
    }
};

// Course Class
class Course {
private:
    string code, title;
    int credits;
    Professor* instructor; // Aggregation

public:
    Course(string c, string t, int cr, Professor* prof) : code(c), title(t), credits(cr), instructor(prof) {}

    void displayCourseDetails() {
        cout << "Course Code: " << code << "\nTitle: " << title << "\nCredits: " << credits << endl;
        if (instructor) {
            cout << "Instructor Details:\n";
            instructor->displayDetails();
        }
    }
};

// GradeBook Class (Encapsulation)
class GradeBook {
private:
    map<string, double> grades; // Student ID -> Grade

public:
    void addGrade(string studentID, double grade) {
        if (grade >= 0.0 && grade <= 4.0) {
            grades[studentID] = grade;
        } else {
            cout << "Invalid grade! Must be between 0.0 and 4.0\n";
        }
    }

    void displayGrades() {
        cout << "\nGradeBook Records:\n";
        for (const auto& entry : grades) {
            cout << "Student ID: " << entry.first << " | Grade: " << entry.second << endl;
        }
    }
};

// EnrollmentManager Class
class EnrollmentManager {
private:
    map<string, vector<string>> enrollments; // Student ID -> Course List

public:
    void enrollStudent(string studentID, string courseCode) {
        enrollments[studentID].push_back(courseCode);
    }

    void displayEnrollments() {
        cout << "\nEnrollments:\n";
        for (const auto& entry : enrollments) {
            cout << "Student ID: " << entry.first << " is enrolled in: ";
            for (const auto& course : entry.second) {
                cout << course << " ";
            }
            cout << endl;
        }
    }
};

// Interactive Menu
int main() {
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
    GradeBook gradeBook;
    EnrollmentManager enrollmentManager;

    int choice;
    while (true) {
        cout << "\n===== University Management System =====\n";
        cout << "1. Add Student\n2. Add Professor\n3. Create Course\n4. Enroll Student\n5. Assign Grade\n6. View Students\n7. View Professors\n8. View Courses\n9. View Enrollments\n10. View Grades\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                string name, ID, contact, enrollmentDate, program;
                int age;
                double GPA;
                cout << "Enter Student Name, Age, ID, Contact, Enrollment Date, Program, GPA: ";
                cin >> name >> age >> ID >> contact >> enrollmentDate >> program >> GPA;
                students.emplace_back(name, age, ID, contact, enrollmentDate, program, GPA);
                cout << "Student added!\n";
                break;
            }
            case 2: {
                string name, ID, contact, department, specialization, hireDate;
                int age;
                cout << "Enter Professor Name, Age, ID, Contact, Department, Specialization, Hire Date: ";
                cin >> name >> age >> ID >> contact >> department >> specialization >> hireDate;
                professors.emplace_back(name, age, ID, contact, department, specialization, hireDate);
                cout << "Professor added!\n";
                break;
            }
            case 3: {
                string code, title;
                int credits;
                int profIndex;
                cout << "Enter Course Code, Title, Credits, Professor Index: ";
                cin >> code >> title >> credits >> profIndex;
                if (profIndex < professors.size()) {
                    courses.emplace_back(code, title, credits, &professors[profIndex]);
                    cout << "Course created!\n";
                } else {
                    cout << "Invalid professor index!\n";
                }
                break;
            }
            case 4: {
                string studentID, courseCode;
                cout << "Enter Student ID and Course Code: ";
                cin >> studentID >> courseCode;
                enrollmentManager.enrollStudent(studentID, courseCode);
                cout << "Student enrolled!\n";
                break;
            }
            case 5: {
                string studentID;
                double grade;
                cout << "Enter Student ID and Grade: ";
                cin >> studentID >> grade;
                gradeBook.addGrade(studentID, grade);
                cout << "Grade assigned!\n";
                break;
            }
            case 6: for (auto& s : students) s.displayDetails(); break;
            case 7: for (auto& p : professors) p.displayDetails(); break;
            case 8: for (auto& c : courses) c.displayCourseDetails(); break;
            case 9: enrollmentManager.displayEnrollments(); break;
            case 10: gradeBook.displayGrades(); break;
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}