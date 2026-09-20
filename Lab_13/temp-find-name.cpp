#include <iostream>
using namespace std;
template <typename T>
T findMin(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    cout << "Integer " << findMin(10, 20) << endl;
    cout << "Double " << findMin(5.5, 2.3) << endl;
    cout << "Character " << findMin('A', 'Z') << endl;

    return 0;
}
