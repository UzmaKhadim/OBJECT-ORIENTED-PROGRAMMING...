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
        cout << "-------------------" << endl;
    }
};
int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    for(int i = 1; i <= n; i++) {
        Student s;
        cout << "\nStudent " << i << ":\n";
        cout << "First Name: ";
        cin >> s.firstName;
        cout << "Last Name: ";
        cin >> s.lastName;
        cout << "Roll Number: ";
        cin >> s.rollNumber;
        cout << "Marks: ";
        cin >> s.marks;
        cout << "\nStudent Information:\n";
        s.displayStudentInfo();  
    }
    return 0;
}
