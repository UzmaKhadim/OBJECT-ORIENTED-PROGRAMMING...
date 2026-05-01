#include <iostream>
#include <string>
using namespace std;
class Product
{
protected:
    string name;
    float price;

public:
    Product(string n, float p)
    {
        name = n;
        price = p;
    }
    void display_product()
    {
        cout << "\n--- Product Information ---" << endl;
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};
class Electronics : public Product
{
private:
    int warrantyYears;

public:
    Electronics(string n, float p, int w) : Product(n, p)
    {
        warrantyYears = w;
    }

    void display_electronics()
    {
        cout << "Warranty Years: " << warrantyYears << endl;
    }
};

int main()
{
    string name;
    float price;
    int warranty;
    cout << "Enter Product Name: ";
    cin >> name;

    cout << "Enter Product Price: ";
    cin >> price;

    cout << "Enter Warranty Years: ";
    cin >> warranty;
    Electronics e(name, price, warranty);
    e.display_product();
    e.display_electronics();
    return 0;
}
