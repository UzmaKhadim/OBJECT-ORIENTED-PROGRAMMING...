#include <iostream>
using namespace std;

class Employee
{
private:
    int employeeID;
    string employeeName;

public:
    static string companyName;
    Employee(int id, string name)
    {
        employeeID = id;
        employeeName = name;
    }

    void display()
    {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Company Name: " << companyName << endl;
        cout << endl;
    }
    static void displayCompanyInfo()
    {
        cout << "Company Name: " << companyName << endl;
    }
};
string Employee::companyName = "Tech Solutions Ltd";

int main()
{
    Employee emp1(101, "Uzma");
    Employee emp2(102, "Aliza");
    Employee emp3(103, "Hania");
    emp1.display();
    emp2.display();
    emp3.display();
    Employee::displayCompanyInfo();

    return 0;
}
