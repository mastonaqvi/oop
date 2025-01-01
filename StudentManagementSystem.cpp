#include <iostream>
#include <string>
using namespace std;
class Student {

    string name;
    int id;
    string courses[3];

public:
    static int totalStudents;

    Student() {
        totalStudents++;
    }

    Student(string name, int id) {
        this->name = name;
        this->id = id;
        totalStudents++;
    }

    Student(const Student& obj) {
        this->name = obj.name;
        this->id = obj.id;
        for (int i = 0; i < 3; i++) {
            this->courses[i] = obj.courses[i];
        }
        totalStudents++;
    }

    ~Student() {
        totalStudents--;
    }

    void setName(string name) {
        this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

    void setCourses(string c1, string c2, string c3) {
        courses[0] = c1;
        courses[1] = c2;
        courses[2] = c3;
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    string* getCourses() {
        return courses;
    }

    void viewDetails() {
        cout << "Name: " << name << ", ID: " << id << ", Courses: ";
        for (int i = 0; i < 3; i++) {
             cout << courses[i]; 
        }
        cout << endl;
    }

    bool operator==(const Student& other) {
        return this->id == other.id;
    }

    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);
};

int Student::totalStudents = 0;

istream& operator>>(istream& in, Student& s) {
    cout << "Enter ID: ";
    in >> s.id;
    cout << "Enter Name: ";
    in >> s.name; 
    cout << "Enter 3 Courses: ";
    for (int i = 0; i < 3; i++) {
        in >> s.courses[i]; 
    }
    return in;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << "Name: " << s.name << ", ID: " << s.id << ", Courses: ";
    for (int i = 0; i < 3; i++) {
        out << s.courses[i] ;
    }
    return out;
}

class Course {
    string courseName;
    int credits;

public:
    static int totalCourses;

    Course() {
        totalCourses++;
    }

    Course(string courseName, int credits) {
        this->courseName = courseName;
        this->credits = credits;
        totalCourses++;
    }

    ~Course() {
        totalCourses--;
    }

    void setCourseName(string name) {
        this->courseName = name;
    }

    void setCredits(int credits) {
        this->credits = credits;
    }

    string getCourseName() {
        return courseName;
    }

    int getCredits() {
        return credits;
    }

    void viewDetails() {
        cout << "Course Name: " << courseName << ", Credits: " << credits << endl;
    }

    int operator+(const Course& other) {
        return this->credits + other.credits;
    }

    friend istream& operator>>(istream& in, Course& c);
    friend ostream& operator<<(ostream& out, const Course& c);
};

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
int main() {
    Student s1("Raza", 296);
    s1.setCourses("OOP", "Discrete Structures", "Islamiyat");
    s1.viewDetails();

    Student s2 = s1;
    s2.setName("Rizqa");
    s2.viewDetails();

    Course c1("OOP", 3);
    Course c2("Discrete Structures", 4);

    c1.viewDetails();
    c2.viewDetails();

    int totalCredits = c1 + c2;
    cout << "Total Credits: " << totalCredits << endl;

    if (s1 == s2) {
        cout << "Students have the same ID." << endl;
    } else {
        cout << "Students have different IDs." << endl;
    }

    cout << "Enter details for a new Student: " << endl;
    Student s3;
    cin >> s3;
    cout << "Details of the new Student: " << s3 << endl;

    cout << "Enter details for a new Course: " << endl;
    Course c3;
    cin >> c3;
    cout << "Details of the new Course: " << c3 << endl;

    return 0;
}
