#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Class Person

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

//Class Person
//Function Defintion

void Person::Per_Set(){
    string tName;
    int tage;
    while(true){
        cout<<"Enter Name: ";
        getline(cin,Name);
        if(tName.empty()==1){
            cout<<endl<<"PLEASE ENTER A NAME"<<endl;
        }else{
            Name=tName;
            break;
        }
    }
    while(true){
        cout<<"Enter Age: ";
        cin>>tage;
        if(tage<17){
            cout<<endl<<"ENTER VALID AGE(>17)"<<endl;
        }else{
            age=tage;
            break;
        }
    }
    cout<<"Enter ID: ";
    cin>>ID;
    cout<<"Enter Contact Information: ";
    getline(cin,Contact_info);
    cout<<endl<<"Information Inserted Successfully"<<endl;
}

void Person::Per_Get(){
    cout<<"Name: "<<Name<<endl<<"Age: "<<age<<endl<<"ID: "<<ID<<endl<<"Contact Information: "<<Contact_info<<endl;
}

//Function Defintion
//Class Student

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

//Class Student
//Function Defintion

void Student::Stu_Set(){
    float tGPA;
    cout<<"Enter Enrollment Date: ";
    getline(cin,Enrollment_Date);
    cout<<"Enter Program Name: ";
    getline(cin,Program);
    while(true){
        cout<<"Enter GPA: ";
        cin>>tGPA;
        if(tGPA>0.0 && tGPA<4.0){
            GPA=tGPA;
        }else{
            cout<<endl<<"ENTER VALID GPA(>0 & <4)"<<endl;
        }
    }

}

void Student::Stu_Get(){
    cout<<"Enrollment Date: "<<Enrollment_Date<<endl<<"Program Name: "<<Program<<endl<<"GPA: "<<GPA<<endl;
}

//Function Defintion
//Class Professor

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

//Class Professor
//Function Defintion

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

//Function Defintion
//Class Course

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

//Class Course
//Function Defintion

void Course::Co_Get(){
    cout<<"Course Code: "<<Course_Code<<endl<<"Title: "<<Title<<endl<<"Credits"<<Credits<<endl<<"Description: "<<Description<<endl;
}

void Course::Co_Set(){
    int TCredits;
    cout<<"Enter Course Code: ";
    getline(cin,Course_Code);
    cout<<"Enter Title: ";
    getline(cin,Title);
    while(true){
        cout<<"Enter Credits: ";
        cin>>TCredits;
        if(TCredits>0){
            Credits=TCredits;
            break;
        }else{
            cout<<endl<<"ENTER VALID CREDITS"<<endl;
        }
    }
    cout<<"Enter Description: ";
    getline(cin,Description);
}

//Function Defintion
//Class Department

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

//Class Department
//Function Defintion

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

//Function Defintion
//Total Classes: 5
//Main Function

int main(){
    while(true){
        cout<<"1. Test Program"<<endl;
        cout<<"1. Test Program"<<endl;
        cout<<"1. Test Program"<<endl;
        cout<<"1. Test Program"<<endl;
        cout<<"1. Test Program"<<endl;
    }

    return 0;
}
