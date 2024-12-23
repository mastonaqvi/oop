#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int id;
        string name;
    public:
        friend ostream &operator<<(ostream& output, Student& data);
        friend istream &operator>>(istream& input, Student& data);
};

ostream &operator<<(ostream& output, Student& data) {
    output << "Student ID: " << data.id << endl;
    output << "Student Name: " << data.name << endl;
    return output;
}

istream &operator>>(istream& input, Student& data) {
    input >> data.id;
    input.ignore(); 
    getline(input, data.name);
    return input;
}

int main() {
    Student stu1, stu2, stu3;
    cout << "Enter the ID and Name of three students (e.g., 123 John Doe):" << endl;
    cin >> stu1 >> stu2 >> stu3;

    cout << "Details of the Students:" << endl;
    cout << stu1 << stu2 << stu3;

    return 0;
}
