#include <iostream>
using namespace std;
class Rectangle
 {
private:
    float length;
    float width;
public:
    Rectangle()
	 {
        length = 1.0;
        width = 1.0;
    }
    Rectangle(float l, float w) 
	{
        length = l;
        width = w;
    }
    Rectangle(float s)
	 {
        length = s;
        width = s;
    }
    float area() 
	{
        return length * width;
    }
    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << endl;
    }
};
int main()
 {
    Rectangle r1;
    Rectangle r2(5.0, 3.0);
    Rectangle r3(4.0);
    cout << "Rectangle 1 (Default Constructor):" << endl;
    r1.display();
    cout << "Rectangle 2 (Parameterized Constructor):" << endl;
    r2.display();
    cout << "Rectangle 3 (Square Constructor):" << endl;
    r3.display();
    return 0;
}
