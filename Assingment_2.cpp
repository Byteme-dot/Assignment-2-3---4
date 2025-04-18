#include<iostream>
#include<vector>
using namespace std;

class Person{
    private:
    string Name;
    int age;
    int ID;
    string Contact_info;
    public:
    Person():Name(""),age(0),ID(0),Contact_info(""){}
    ~Person(){}
    void Per_Set();
    void Per_Get();
};

void Person::Per_Set(){
    cout<<"Enter Name: ";
    getline(cin,Name);
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter ID: ";
    cin>>ID;
    cout<<"Enter Contact Information: ";
    getline(cin,Contact_info);
    cout<<endl<<"Information Inserted Successfully"<<endl;
}

void Person::Per_Get(){
    cout<<"Name: "<<Name<<endl<<"Age: "<<age<<endl<<"ID: "<<ID<<endl<<"Contact Information: "<<Contact_info<<endl;
}

class Student{
    private:
    string Enrollment_Date;
    string Program;
    float GPA;
    public:
    Student():Enrollment_Date(""),Program(""),GPA(0.0){}
    ~Student(){}

    void Stu_Get();
    void Stu_Set();

};

void Student::Stu_Set(){
    cout<<"Enter Enrollment Date: ";
    getline(cin,Enrollment_Date);
    cout<<"Enter Program Name: ";
    getline(cin,Program);
    cout<<"Enter GPA: ";
    cin>>GPA;

}

void Student::Stu_Get(){
    cout<<"Enrollment Date: "<<Enrollment_Date<<endl<<"Program Name: "<<Program<<endl<<"GPA: "<<GPA<<endl;
}

class Professor{
    private:
    string Department;
    string Specialization;
    string Hire_Date;

    public:
    Professor():Department(""),Specialization(""),Hire_Date(""){}
    
    ~Professor(){}

    void Pro_Set();
    void Pro_Get();
};

void Professor::Pro_Get(){
    cout<<"Department: "<<Department<<endl<<"Specialization: "<<Specialization<<endl<<"Hire Date: "<<Hire_Date<<endl;
}

void Professor::Pro_Set(){
    cout<<"Enter Department Name: ";
    getline(cin,Department);
    cout<<"Enter Specialization Name: ";
    getline(cin,Specialization);
    cout<<"Enter Hire Date: ";
    getline(cin,Hire_Date);
}

class Course{
    private:
    string Course_Code;
    string Title;
    int Credits;
    string Description;
    public:
    Course():Course_Code(""),Title(""),Credits(0),Description(""){}

    ~Course(){}

    void Co_Get();
    void Co_Set();

};

void Course::Co_Get(){
    cout<<"Course Code: "<<Course_Code<<endl<<"Title: "<<Title<<endl<<"Credits"<<Credits<<endl<<"Description: "<<Description<<endl;
}

void Course::Co_Set(){
    cout<<"Enter Course Code: ";
    getline(cin,Course_Code);
    cout<<"Enter Title: ";
    getline(cin,Title);
    cout<<"Enter Credits: ";
    cin>>Credits;
    cout<<"Enter Description: ";
    getline(cin,Description);
}

class Department{
    private:
    string Name;
    string Location;
    double Budget;
    public:
    Department():Name(""),Location(""),Budget(0.00){}

    ~Department(){}

    void Dep_Set();
    void Dep_Get();
};

void Department::Dep_Get(){
    cout<<"Name: "<<Name<<endl<<"Location: "<<Location<<endl<<"Budget: "<<Budget<<endl;
}

void Department::Dep_Set(){
    cout<<"Enter Name: ";
    getline(cin,Name);
    cout<<"Enter Location: ";
    getline(cin,Location);
    cout<<"Enter Budget: ";
    cin>>Budget;
}

int main(){
    while(true){
        
    }

    return 0;
}
