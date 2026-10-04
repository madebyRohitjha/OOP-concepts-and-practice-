Student Book Management System

Project Overview

The Student Book Management System is a simple C++ university project designed to manage books and students using basic Object-Oriented Programming (OOP) concepts.

The system allows users to add books, display available books, register students, issue books to students, and return books.

The project is designed to be simple and easy to understand for students who are learning C++ and OOP.

Objectives

* Learn and demonstrate basic OOP concepts in C++
* Manage student and book information
* Allow students to borrow and return books
* Practice classes, objects, functions, and encapsulation
* Create a simple real-world university project

Main Features

1. Add a new book
2. Display all books
3. Add a student
4. Display all students
5. Issue a book to a student
6. Return a book
7. Check book availability
8. Exit the program

OOP Concepts Used

1. Class

The system can use classes such as:

* Book
* Student
* Library
* LibraryManagement

2. Object

Objects are created from these classes to represent real-world entities.

For example:

Book book1;
Student student1;

3. Encapsulation

Book and student information can be kept private and accessed through public member functions.

4. Member Functions

Functions are used to perform operations such as:

* Adding books
* Displaying books
* Issuing books
* Returning books
* Registering students

5. Constructors

Constructors can be used to initialize book and student information when objects are created.

Example Data

Book

* Book ID
* Book Name
* Author Name
* Availability Status

Student

* Student ID
* Student Name
* Department
* Borrowed Book

Technologies Used

* Programming Language: C++
* Programming Concept: Object-Oriented Programming
* Compiler: GCC / MinGW
* IDE: Visual Studio Code, Code::Blocks, Dev-C++, or Visual Studio

Project Structure

Student-Book-Management-System/
│
├── main.cpp
├── README.md
└── ...

How to Run

Step 1

Open the project in a C++ IDE such as Visual Studio Code or Code::Blocks.

Step 2

Compile the program:

g++ main.cpp -o library

Step 3

Run the program:

./library

On Windows:

library.exe

Sample Menu

===== Student Book Management System =====
1. Add Book
2. Display Books
3. Add Student
4. Display Students
5. Issue Book
6. Return Book
7. Exit
Enter your choice:

Future Improvements

The project can be improved by adding:

* File handling for permanent data storage
* Search functionality
* Fine calculation for late book returns
* Login system
* Book categories
* Multiple books per student
* Database connectivity
* Graphical user interface

Conclusion

The Student Book Management System is a basic C++ project that demonstrates how OOP concepts can be applied to a real-world university library scenario. It provides practical experience with classes, objects, encapsulation, constructors, and member functions while keeping the implementation simple and understandable for students.
