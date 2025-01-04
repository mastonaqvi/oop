#include <iostream>
#include "student.h"

Student::Student(string major, double gpa, string name, int age) : Person(name, age) {
    this->major = major;
    this->gpa = gpa;
}

void Student::displayStudent() {
    cout << "Major: " << major << endl;
    cout << "GPA: " << gpa << endl;
    displayPerson();
}
