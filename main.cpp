#include <iostream>
using namespace std;

class Student{

    int age;
    float cgpa;
    char* name;


public:
//setters

  void setAge(int Parameter){
    age=Parameter;
  }
  void setCGPA(float cgpaParameter){
    cgpa=cgpaParameter;
  }
  void setName(char*);
//getters

   int getage(){
    return age;
   }
   float getcpga(){
    return cgpa;
   }



};
int main(){
    Student one;
    int age1=20;
    float cgpa1=3.14;

    one.setAge(age1);
    one.setCGPA(cgpa1);

    Student two;
     
    int age2=30;
    float cgpa2=2.14;


    two.setAge(age2);
    two.setCGPA(cgpa2);

    cout<<one.getage()<<endl;
    cout<<two.getcpga()<<endl;

   return 0;
}