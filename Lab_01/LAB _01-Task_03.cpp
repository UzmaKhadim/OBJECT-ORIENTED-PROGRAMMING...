#include <iostream>
#include <string>
using namespace std;
struct Student {
    string firstName;
    string lastName;
    int rollNumber;
    float marks;
    void displayStudentInfo() {
        cout << "Full Name: " << firstName << " " << lastName << endl;
        cout << "Marks: " << marks << endl;
    }
};
int main() {
    Student student;      
    Student* ptr = &student;
    cout << "Enter first name: ";
    cin >> ptr->firstName;
    cout << "Enter last name: ";
    cin >> ptr->lastName;
    cout << "Enter roll number: ";
    cin >> ptr->rollNumber;
    cout << "Enter marks: ";
    cin >> ptr->marks;
    cout << "\nStudent Information:\n";
    ptr->displayStudentInfo();
    return 0;
}
