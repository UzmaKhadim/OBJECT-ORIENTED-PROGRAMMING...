#include<iostream>
using namespace std;
class Student
{
	public:
	string name;
	int rollNo;
	float marks;
	void getData()
	{
		cout<<"Enter student name:"<<endl;
		cin>>name;
		cout<<"Enter student roll number:"<<endl;
		cin>>rollNo;
		cout<<"Enter student marks:"<<endl;
		cin>>marks;
	}
	void displayData()
	{
		cout<<"STUDENT INFORMATION";
		cout<<"Name:"<<name<<endl;
		cout<<"RollNo:"<<rollNo<<endl;
		cout<<"Marks:"<<marks<<endl;
	}
};
int main()
{
	Student s1;
	s1.getData();
	s1.displayData();
	return 0;
}
