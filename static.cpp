#include <iostream>
using namespace std;

class Counter {
private:
    static int objectCount;
    int id;

public:
    Counter() {
        objectCount++;
        id = objectCount;
        cout << "Object with ID " << id << " created." << endl;
    }

    ~Counter() {
        cout << "Object with ID " << id << " destroyed." << endl;
        objectCount--;
    }

    static int getTotalObjects() {
        return objectCount;
    }

    int getId() const {
        return id;
    }

    void displayInfo() const {
        cout << "Object ID: " << id << ", Total objects: " << objectCount << endl;
    }
};

int Counter::objectCount = 0;

int main() {
    Counter c1;
    c1.displayInfo();
    
    Counter c2;
    c2.displayInfo();
    
    Counter c3;
    c3.displayInfo();
    
    cout << "\nTotal objects created: " << Counter::getTotalObjects() << endl;

    Counter* c4 = new Counter();
    c4->displayInfo();
    
    cout << "\nTotal objects created: " << Counter::getTotalObjects() << endl;

    delete c4;
    
    cout << "\nTotal objects created: " << Counter::getTotalObjects() << endl;

    return 0;
}
