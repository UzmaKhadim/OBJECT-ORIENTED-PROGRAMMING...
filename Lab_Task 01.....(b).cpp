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
	int n;
	cout<<"Enter number of students:";
	cin>>n;
	Student s[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter details of students"<<i+1<<endl;
		cout<<"First name:";
		cin>>s[i].first_name;
		cout<<"Last name:";
		cin>>s[i].last_name;
		cout<<"Roll No:";
		cin>>s[i].rollNo;
		cout<<"Marks:";
		cin>>s[i].mark;
	}
	cout<<" \nSTUDENT INFORMATION\n";
	for(int i=0;i<n;i++){
	
		s[i].dispalyStudentInfo();
		cout<<endl;
	}
	return 0;
}

