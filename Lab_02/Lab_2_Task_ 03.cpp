#include <iostream>
using namespace std;
class Voter
{
public:
    string name;
    int age;
    bool isEligible();  
};
bool Voter::isEligible()
{
    if (age > 18)
        return true;
    else
        return false;
}
int main()
{
    Voter v;
    cout << "Enter your name: ";
    cin >> v.name;
    cout << "Enter your age: ";
    cin >> v.age;
    if (v.isEligible())
        cout << v.name << " is eligible to vote." << endl;
    else
        cout << v.name << " is NOT eligible to vote." << endl;
    return 0;
}
