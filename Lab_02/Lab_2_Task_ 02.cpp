#include <iostream>
using namespace std;
class Rectangle
{
public:
    int length;
    int width;
    void setDimensions();
    int area();
    int perimeter();
};
void Rectangle::setDimensions()
{
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;
}
int Rectangle::area()
{
    return length * width;
}
int Rectangle::perimeter()
{
    return 2 * (length + width);
}
int main()
{
    Rectangle r;
    r.setDimensions();
    cout << "Area = " << r.area();
    cout << "Perimeter = " << r.perimeter();
    return 0;
}
