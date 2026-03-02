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
	s1.first_name="Uzma";
	s1.last_name="Khadim";
	s1.rollNo=01;
	s1.mark=91.5;
	
	
    s1.dispalyStudentInfo();
	return 0;
	
}
