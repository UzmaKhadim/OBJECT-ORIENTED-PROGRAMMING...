#include<iostream>
using namespace std;
struct Student
{
	int rollNo;
	string first_name;
	string last_name;
	float mark;
	void dispalyStudentInfo()
	{
		cout<<"Full name:"<<first_name<<" "<<last_name<<endl;
		cout<<"Mark:"<<mark<<endl;
	}
};
int main()
{
	Student s1;
	Student *ptr;
	ptr=&s1;
	ptr->first_name="Uzma";
	ptr->last_name="Khadim";
	ptr->rollNo=01;
	ptr->mark=90;
	ptr->dispalyStudentInfo();
	return 0;
}
