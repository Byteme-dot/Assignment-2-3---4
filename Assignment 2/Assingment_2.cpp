#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ------------------------------ PERSON CLASS ---------------------------------
class Person {
protected:
    string name;
    int age;
    int ID;
    string contact_info;

public:
    Person() : name(""), age(0), ID(0), contact_info("") {}

    void setDetails() {
        cout << "Enter Name: ";
        getline(cin, name);

        while (true) {
            cout << "Enter Age: ";
            cin >> age;
            if (age < 17) {
                cout << "Invalid Age (must be >17). Try again.\n";
            } else {
                break;
            }
        }
        cin.ignore();

        cout << "Enter ID: ";
        cin >> ID;
        cin.ignore();
        cout << "Enter Contact Information: ";
        getline(cin, contact_info);
        cout << "Person information saved.\n";
    }

    void displayDetails() const {
        cout << "\nPerson Details:\n";
        cout << "Name: " << name << "\nAge: " << age << "\nID: " << ID 
             << "\nContact: " << contact_info << endl;
    }
};

// ---------------------------- STUDENT CLASS -----------------------------------
class Student : public Person {
private:
    string enrollmentDate;
    string program;
    float GPA;

public:
    Student() : enrollmentDate(""), program(""), GPA(0.0) {}

    void setDetails() {
        Person::setDetails();
        cin.ignore();

        cout << "Enter Enrollment Date: ";
        getline(cin, enrollmentDate);

        cout << "Enter Program Name: ";
        getline(cin, program);

        while (true) {
            cout << "Enter GPA (0.0 - 4.0): ";
            cin >> GPA;
            if (GPA < 0.0 || GPA > 4.0) {
                cout << "Invalid GPA. Try again.\n";
            } else {
                break;
            }
        }
        cin.ignore();
    }

    void displayDetails() const {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate << "\nProgram: " << program
             << "\nGPA: " << GPA << endl;
    }
};

// -------------------------- PROFESSOR CLASS -----------------------------------
class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;

public:
    Professor() : department(""), specialization(""), hireDate("") {}

    void setDetails() {
        Person::setDetails();
        cin.ignore();

        cout << "Enter Department Name: ";
        getline(cin, department);

        cout << "Enter Specialization: ";
        getline(cin, specialization);

        cout << "Enter Hire Date: ";
        getline(cin, hireDate);
    }

    void displayDetails() const {
        Person::displayDetails();
        cout << "Department: " << department << "\nSpecialization: " << specialization
             << "\nHire Date: " << hireDate << endl;
    }
};

// ----------------------------- COURSE CLASS ----------------------------------
class Course {
private:
    string courseCode;
    string title;
    int credits;
    string description;

public:
    Course() : courseCode(""), title(""), credits(0), description("") {}

    void setDetails() {
        cout << "Enter Course Code: ";
        getline(cin, courseCode);

        cout << "Enter Title: ";
        getline(cin, title);

        while (true) {
            cout << "Enter Credits (positive value): ";
            cin >> credits;
            if (credits <= 0) {
                cout << "Invalid Credits. Try again.\n";
            } else {
                break;
            }
        }
        cin.ignore();

        cout << "Enter Description: ";
        getline(cin, description);
    }

    void displayDetails() const {
        cout << "\nCourse Details:\n";
        cout << "Course Code: " << courseCode << "\nTitle: " << title
             << "\nCredits: " << credits << "\nDescription: " << description << endl;
    }
};

// -------------------------- MAIN FUNCTION ------------------------------------
int main() {
    vector<Person*> people;
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course*> courses;

    while (true) {
        int choice;
        cout << "\n============== MENU ==============\n";
        cout << "1. Add Person Data\n2. Display All Persons\n";
        cout << "3. Add Student Data\n4. Display All Students\n";
        cout << "5. Add Professor Data\n6. Display All Professors\n";
        cout << "7. Add Course Data\n8. Display All Courses\n";
        cout << "0. Exit\n==================================\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 0:
                cout << "Exiting Program.\n";
                return 0;

            case 1: {
                Person *p = new Person();
                p->setDetails();
                people.push_back(p);
                break;
            }
            case 2: {
                if (people.empty()) {
                    cout << "No Person Data Available!\n";
                } else {
                    for (auto &p : people) p->displayDetails();
                }
                break;
            }

            case 3: {
                Student *s = new Student();
                s->setDetails();
                students.push_back(s);
                break;
            }
            case 4: {
                if (students.empty()) {
                    cout << "No Student Data Available!\n";
                } else {
                    for (auto &s : students) s->displayDetails();
                }
                break;
            }

            case 5: {
                Professor *prof = new Professor();
                prof->setDetails();
                professors.push_back(prof);
                break;
            }
            case 6: {
                if (professors.empty()) {
                    cout << "No Professor Data Available!\n";
                } else {
                    for (auto &prof : professors) prof->displayDetails();
                }
                break;
            }

            case 7: {
                Course *c = new Course();
                c->setDetails();
                courses.push_back(c);
                break;
            }
            case 8: {
                if (courses.empty()) {
                    cout << "No Course Data Available!\n";
                } else {
                    for (auto &c : courses) c->displayDetails();
                }
                break;
            }

            default:
                cout << "Invalid Choice. Try Again.\n";
        }
    }
}