#include "person.h"

class Student : public Person {
    string major;
    double gpa;

public:
    Student(string major, double gpa, string name, int age);
    void displayStudent();
};

