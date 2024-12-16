#include <iostream>
#include <string>
using namespace std;

class Student {
	string name;
	int id;
	double grade;

public:
	void setname(string name) {
		this->name = name;
	}
	string getname() {
		return name;
	}
	void setid(int id) {
		this->id = id;
	}
	int getid() {
		return id;
	}
	void setgrade(double grade) {
		this->grade = grade;
	}
	double getgrade() {
		return grade;
	}
	void setgrade(int grade) {
		this->grade = grade;
	}
	

	void dispaly(){
		

		cout << "Student Created : " << name << endl;
		cout << "Id : " << id << endl;
		cout << "Grade : " << grade << endl;
		
	}
	~Student() {
		cout << "Deleting Student: " << name << endl;
	}
};

int main() {
	Student* student1 = new Student();
	student1->setname("Alice");
	student1->setid(101);
	student1->setgrade(88.5);
	student1->dispaly();

	student1->setname("Alice Johnson");
	cout << "Updated Name: " << student1->getname() << endl;

	student1->setgrade(90);
	cout << "Grade updated to: " << student1->getgrade() << endl;

	student1->setgrade(30);
	cout << "Grade updated to default: " << student1->getgrade() << endl;

	student1->dispaly();

	Student* student2 = new Student();
	student2->setname("Bob");
	student2->setid(102);
	student2->setgrade(50);
	student2->dispaly();

	delete student1;
	delete student2;

	return 0;
}
