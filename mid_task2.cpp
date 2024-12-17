#include <iostream>
#include <string>
using namespace std;

class ComplexNumber {

    double realPart;
    double imaginaryPart;
    static int totalComplexNumbers;
    const double PI = 3.14159;

public:
    ComplexNumber() {
        realPart = 0;
        imaginaryPart = 0;
        totalComplexNumbers++;
        cout << "Complex Number created: (" << realPart << " + " << imaginaryPart << "i)" << endl;
    }

    ComplexNumber(double real, double imaginary) {
        realPart = real;
        imaginaryPart = imaginary;
        totalComplexNumbers++;
        cout << "Complex Number created: (" << realPart << " + " << imaginaryPart << "i)" << endl;
    }

    ~ComplexNumber() {
        cout << "Deleting Complex Number: (" << realPart << " + " << imaginaryPart << "i)" << endl;
        totalComplexNumbers--;
    }

    static int getTotalComplexNumbers() {
        return totalComplexNumbers;
    }

    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(this->realPart + other.realPart, this->imaginaryPart + other.imaginaryPart);
    }

    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(this->realPart - other.realPart, this->imaginaryPart - other.imaginaryPart);
    }

    ComplexNumber& operator++() {
        this->realPart++;
        this->imaginaryPart++;
        return *this;
    }

    ComplexNumber operator++(int) {
        ComplexNumber temp = *this;
        this->realPart++;
        this->imaginaryPart++;
        return temp;
    }

    ComplexNumber& operator--() {
        this->realPart--;
        this->imaginaryPart--;
        return *this;
    }

    ComplexNumber operator--(int) {
        ComplexNumber temp = *this;
        this->realPart--;
        this->imaginaryPart--;
        return temp;
    }

    void display() const {
        cout << "(" << realPart << " + " << imaginaryPart << "i)" << endl;
    }
};

int ComplexNumber::totalComplexNumbers = 0;

int main() {
    ComplexNumber* complex1 = new ComplexNumber(3.5, 4.5);
    complex1->display();

    ++(*complex1);
    cout << "Incremented Complex Number: ";
    complex1->display();

    (*complex1)++;
    cout << "Post-increment Complex Number: ";
    complex1->display();

    --(*complex1);
    cout << "Decremented Complex Number: ";
    complex1->display();

    ComplexNumber* complex2 = new ComplexNumber(5.0,-2.0);
    complex2->display();

    cout << "Total Complex Numbers: " << ComplexNumber::getTotalComplexNumbers() << endl;

    delete complex1;
    delete complex2;
    


    cout << "Total Complex Numbers: " << ComplexNumber::getTotalComplexNumbers() << endl;

    return 0;
}

