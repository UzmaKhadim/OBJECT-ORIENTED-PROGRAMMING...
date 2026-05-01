#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
    string name;
    float salary;
public:
    void input_employee()
    {
        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display_employee()
    {
        cout << "\n--- Employee Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};
class Developer : public Employee
{
private:
    string programming_language;

public:
    void input_developer()
    {
        cout << "Enter Programming Language: ";
        cin >> programming_language;
    }

    void display_developer()
    {
        cout << "\n--- Developer Information ---" << endl;
        cout << "Programming Language: " << programming_language << endl;
    }
};
class Designer : public Employee
{
private:
    string design_tool;

public:
    void input_designer()
    {
        cout << "Enter Design Tool: ";
        cin >> design_tool;
    }

    void display_designer()
    {
        cout << "\n--- Designer Information ---" << endl;
        cout << "Design Tool: " << design_tool << endl;
    }
};

int main()
{
    Developer d;

    cout << "Enter Developer Details" << endl;
    d.input_employee();
    d.input_developer();
    Designer ds;

    cout << "\nEnter Designer Details" << endl;
    ds.input_employee();
    ds.input_designer();
    d.display_employee();
    d.display_developer();
    ds.display_employee();
    ds.display_designer();

    return 0;
}
