#include<iostream>
using namespace std;
class Employee
{
	private:
	int id;
	string name;
	float salary;
	public:
		Employee()
		{
			id=0;
			name="Not Assigned";
			salary=0.0;
		}
		void displaydetails()
		{
			cout<<"Name:"<<name;
			cout<<"Id:"<<id;
			cout<<"Salary:"<<salary;
		}
};
int main()
{
	Employee e;
}
