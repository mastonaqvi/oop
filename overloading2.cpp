#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double realPart;
    double imaginaryPart;

public:
   
    ComplexNumber(){
        realPart=0.0;
        imaginaryPart=0.0;

    } 

   
    ComplexNumber(double real, double imaginary) {
        realPart=real;
        imaginaryPart=imaginary;

    } 

  
    double getRealPart() const {
        return realPart;
    }

    double getImaginaryPart() const {
        return imaginaryPart;
    }

    
    void setRealPart(double real) {
        realPart = real;
    }

    void setImaginaryPart(double imaginary) {
        imaginaryPart = imaginary;
    }

   
    void display() const {
        cout << realPart << " + " << imaginaryPart << "i" << endl;
    }

   
    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(this->realPart + other.realPart, this->imaginaryPart + other.imaginaryPart);
    }

   
    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(this->realPart - other.realPart, this->imaginaryPart - other.imaginaryPart);
    }

    
    bool operator==(const ComplexNumber& other) {
        return (this->realPart == other.realPart && this->imaginaryPart == other.imaginaryPart);
    }

   
    bool operator!=(const ComplexNumber & other) {
        return !(*this == other); 
    }

   
    ComplexNumber& operator++() {
        this->realPart += 1;
        this->imaginaryPart += 1;
        return *this;
    }

  
    ComplexNumber operator++(int) {
        ComplexNumber temp = *this; 
        this->realPart += 1;
        this->imaginaryPart += 1;
        return temp; 
    }

   
    ComplexNumber& operator--() {
        this->realPart -= 1;
        this->imaginaryPart -= 1;
        return *this;
    }

    
    ComplexNumber operator--(int) {
        ComplexNumber temp = *this; 
        this->realPart -= 1;
        this->imaginaryPart -= 1;
        return temp; 
    }
};

int main() {
    
    ComplexNumber c1(6.0, 3.0);
    ComplexNumber c2(25.0, -30.0);

  
    cout << "Complex Number 1: ";
    c1.display();
    cout << "Complex Number 2: ";
    c2.display();

   
    ComplexNumber c3 = c1 + c2;
    cout << "Sum (c1 + c2): ";
    c3.display();

   
    ComplexNumber c4 = c1 - c2;
    cout << "Difference (c1 - c2): ";
    c4.display();

   
    if (c1 == c2) {
        cout << "c1 is equal to c2." << endl;
    } else {
        cout << "c1 is not equal to c2." << endl;
    }

 
    if (c1 != c4) {
        cout << "c1 is not equal to c4." << endl;
    }

 
    ++c1;
    cout << "c1 after pre-increment: ";
    c1.display();

   
    c2++;
    cout << "c2 after post-increment: ";
    c2.display();


    --c1;
    cout << "c1 after pre-decrement: ";
    c1.display();

  
    c2--;
    cout << "c2 after post-decrement: ";
    c2.display();

    return 0;
}
