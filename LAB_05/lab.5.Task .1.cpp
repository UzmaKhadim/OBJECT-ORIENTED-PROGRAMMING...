#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    void inputPerson() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class
class Student : public Person {
private:
    int student_ID;

public:
    void inputStudent() {
        inputPerson();  // call base class function
        cout << "Enter Student ID: ";
        cin >> student_ID;
    }

    void displayStudentInfo() {
        displayPersonInfo();  // call base class function
        cout << "Student ID: " << student_ID << endl;
    }
};

int main() {
    Student s;

    cout << "Enter Student Details:\n";
    s.inputStudent();

    cout << "\n--- Student Information ---\n";
    s.displayStudentInfo();

    return 0;
}
