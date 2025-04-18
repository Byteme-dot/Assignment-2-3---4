Assignment 2:
    Part A: Classes and Objects
        1. Create the following classes with appropriate attributes:
            o Person (with attributes: name, age, ID, contact information)
            o Student (with attributes: enrollment date, program, GPA)
            o Professor (with attributes: department, specialization, hire date)
            o Course (with attributes: code, title, credits, description)
            o Department (with attributes: name, location, budget)
        2. Implement constructors, destructors, and basic getter/setter methods for each class.
        3. Create a test program that instantiates at least two objects of each class.
    Part B: Encapsulation
        1. Refactor all classes to make attributes private.
        2. Implement public getter and setter methods with proper validation:
            o Age should be positive and reasonable
            o GPA should be between 0.0 and 4.0
            o Course credits should be positive
            o Names should not be empty
        3. Create these encapsulated classes:
            o GradeBook: Manages grades for a course (stores student IDs and their grades)
            o EnrollmentManager: Handles student enrollment in courses (tracks which students are in which courses)
        4. Implement methods in these classes that encapsulate complex operations:
            o GradeBook: calculateAverageGrade(), getHighestGrade(),getFailingStudents()
            o EnrollmentManager: enrollStudent(), dropStudent(), getEnrollmentCount()
    Part C: Polymorphism
        1. Add a displayDetails() method to the Person class.
        2. Override the displayDetails() method in both Student and Professor classes.
        3. Implement a calculatePayment() method in Person and override it in appropriate subclasses.
        4. Create a test function that accepts a Person pointer/reference and calls these polymorphic methods.
        5. Create an array of Person pointers containing both Student and Professor objects, and demonstrate
         polymorphic behavior by iterating through the array.

        Deliverables
            1. Complete source code with all classes implemented
            2. Test program demonstrating:
                o Object creation and manipulation
                o Encapsulation with validation
                o Polymorphic behavior
            3. Brief documentation explaining your implementation choices
        Evaluation Criteria
            • Proper implementation of classes and objects
            • Effective encapsulation with meaningful validation
            • Correct implementation of polymorphism
            • Code organization and readability
            • Appropriate use of OOP principles
