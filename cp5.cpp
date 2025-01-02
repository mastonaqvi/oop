#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:
    string name;
    int age;

    public:
    Person(string name, int age){
        this->name=name;
        this->age=age;
    }
    void displayPerson(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }

};
class Faculty:  public Person{
    string department;
    double salary;

    public:
    Faculty(string department, double salary,string name, int age):Person( name, age){
        this->department=department;
        this->salary=salary;
    }
    void displayFaculty(){
        cout<<"Department: "<<department<<endl;
        cout<<"Salary: "<<salary<<endl;
        displayPerson();

    }
};
class Student: public Person{
    string major;
    double gpa;

    public:
    Student(string major, double gpa,string name, int age):Person( name, age){
        this->major=major;
        this->gpa=gpa;
    }
    void displayStudent(){
        cout<<"major: "<<major<<endl;
        cout<<"gpa: "<<gpa<<endl;
        displayPerson();
    }

};
class Course{
    string courseName;
    Faculty*instructor;
    Student*students[3];

    Course(string oop,Faculty* courseinstructor){
       courseName=oop;
       Faculty*instructor=courseinstructor;
       for(int i=0; i<3; i++){
        students[i]=nullptr;
       }
    }
   void addStudent(Student* student, int index) {
        if (index < 0 || index >= 3) {
            cout << "Index out of range. Valid indices are 0-2." << endl;
            return;
        }
        students[index] = student;
    }

    void displayCourse() {
        cout << "Course Name: " << courseName << endl;
        cout << "Instructor Details:" << endl;
        instructor->displayFaculty();
        cout << "Enrolled Students:" << endl;
        for (int i = 0; i < 3; ++i) {
            if (students[i]) {
                cout << "Student " << i + 1 << ":" << endl;
                students[i]->displayStudent();
            } else {
                cout << "Student " << i + 1 << ": None" << endl;
            }
        }
    }

   
    ~Course() {
        for (int i = 0; i < 3; ++i) {
            if (students[i]) {
                delete students[i];
                students[i] = nullptr;
            }
        }
    }


};


int main(){
    faculty* faculty1 = new Faculty("Dr. Smith", 45, "Computer Science", 120000);
        Faculty* faculty2 = new Faculty("Dr. Johnson", 50, "Mathematics", 110000);

        // Create students
        Student* student1 = new Student("Alice", 20, "Computer Science", 3.8);
        Student* student2 = new Student("Bob", 22, "Mathematics", 3.5);
        Student* student3 = new Student("Charlie", 21, "Physics", 3.9);

        // Create a course and assign an instructor
        Course course("Data Structures", faculty1);

        // Add students to the course
        course.addStudent(student1, 0);
        course.addStudent(student2, 1);
        course.addStudent(student3, 2);

        // Display details
        course.displayCourse();

        // Clean up memory
        delete faculty1;
        delete faculty2;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;


}