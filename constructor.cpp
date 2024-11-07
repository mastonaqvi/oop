#include <iostream>
using namespace std;

class Student {
    int age;
    float cgpa;
    char* name;

public:
    
    Student() {
        age = 20;
        cgpa = 0.0;
        name = nullptr;
    }

   
    Student(int myage) {
        age = myage;
        cgpa = 0.0;
        name = nullptr;
    }

   
    Student(int a, float b, char* myname) {
        age = a;
        cgpa = b;

        
        int length= strlen(myname);

        name = new char[length + 1];  // Allocate memory for name
        for (int i = 0; i < length; i++) {
            name[i] = myname[i];
        }
        name[length] = '\0';
    }

  
    int getAge()  {
        return age;
    }

    // Getter for cgpa
    float getCgpa()  {
        return cgpa;
    }

    // Getter for name
    char* getName()  {
        return name;
    }
};

int main() {
    Student one;
    cout << "Default Constructor - Age: " << one.getAge() << endl;

    Student two(20);
    cout << "Single Parameter Constructor - Age: " << two.getAge() << endl;

    Student three(20, 3.4, "Raza");
    cout << "Three Parameter Constructor - Age: " << three.getAge() 
         << ", CGPA: " << three.getCgpa() 
         << ", Name: " << three.getName() << endl;

    return 0;
}
