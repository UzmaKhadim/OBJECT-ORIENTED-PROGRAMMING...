// calculator.cpp
#include <iostream>
using namespace std;
class Calculator
{
public:
    float num1, num2;
    float add();
    float subtract();
    float multiply();
    float divide();
};
float Calculator::add() {
    return num1 + num2;
}
float Calculator::subtract() {
    return num1 - num2;
}
float Calculator::multiply() {
    return num1 * num2;
}
float Calculator::divide() {
    if (num2 != 0)
        return num1 / num2;
    else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}
int main()
{
    Calculator calc;
    int choice;
    cout << "Enter first number: ";
    cin >> calc.num1;
    cout << "Enter second number: ";
    cin >> calc.num2;
    cout << "\nChoose operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch(choice) {
        case 1: cout << "Result: " << calc.add() << endl; break;
        case 2: cout << "Result: " << calc.subtract() << endl; break;
        case 3: cout << "Result: " << calc.multiply() << endl; break;
        case 4: cout << "Result: " << calc.divide() << endl; break;
        default: cout << "Invalid choice!" << endl;
    }
    return 0;
}
