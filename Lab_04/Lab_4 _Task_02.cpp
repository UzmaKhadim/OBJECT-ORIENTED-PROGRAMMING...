#include<iostream>
using namespace std;
class BankAccount
{
	private:
	string accountNumber;
	string accountHolder;
	double balance;
	public:
		BankAccount(string aN,string aH,double b)
		{
			accountNumber=aN;
			accountHolder=aH;
			balance=b;
		}
		void showAccountDetails()
		{
			cout<<"Account Number:"<<accountNumber;
			cout<<"Account Holder:"<<accountHolder;
			cout<<"Balance:"<<balance;
		}		
	
};
int main()
{
	BankAccount bA(PKD,Muhammad Awais,100000)
}
