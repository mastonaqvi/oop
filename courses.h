#include <iostream>
#include <string>
using namespace std;

class Course {
    string courseName;
    int credits;

public:
    static int totalCourses;

    Course();
    Course(string courseName, int credits);
    ~Course();

    void setCourseName(string name);
    void setCredits(int credits);
    string getCourseName();
    int getCredits();
    void viewDetails();
    int operator+(const Course& other);

    friend istream& operator>>(istream& in, Course& c);
    friend ostream& operator<<(ostream& out, const Course& c);
};
