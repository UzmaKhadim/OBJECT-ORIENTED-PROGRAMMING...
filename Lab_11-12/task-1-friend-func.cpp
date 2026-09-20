#include <iostream>
using namespace std;

class Box
{
private:
    int length;

public:
    Box(int l)
    {
        length = l;
    }
    friend void displayLength(Box b);
};
void displayLength(Box b)
{
    cout << "Length of Box: " << b.length << endl;
}

int main()
{
    Box b1(10);
    displayLength(b1);

    return 0;
}
