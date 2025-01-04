#include "courses.h"

Course::Course() {
    totalCourses++;
}

Course::Course(string courseName, int credits) {
    this->courseName = courseName;
    this->credits = credits;
    totalCourses++;
}

Course::~Course() {
    totalCourses--;
}

void Course::setCourseName(string name) {
    this->courseName = name;
}

void Course::setCredits(int credits) {
    this->credits = credits;
}

string Course::getCourseName() {
    return courseName;
}

int Course::getCredits() {
    return credits;
}

void Course::viewDetails() {
    cout << "Course Name: " << courseName << ", Credits: " << credits << endl;
}

int Course::operator+(const Course& other) {
    return this->credits + other.credits;
}

int Course::totalCourses = 0;

istream& operator>>(istream& in, Course& c) {
    cout << "Enter Course Name: ";
    in >> c.courseName;
    cout << "Enter Credits: ";
    in >> c.credits;
    return in;
}

ostream& operator<<(ostream& out, const Course& c) {
    out << "Course Name: " << c.courseName << ", Credits: " << c.credits;
    return out;
}
