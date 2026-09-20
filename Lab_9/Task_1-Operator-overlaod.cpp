#include <iostream>
using namespace std;

class Distance {
private:
    int feet, inches;

public:
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    bool operator==(Distance d) {
        if (feet == d.feet && inches == d.inches)
            return true;
        else
            return false;
    }
};

int main() {
    Distance d1(4, 10);
    Distance d2(4, 10);

    if (d1 == d2)
        cout << "Distances are equal" << endl;
    else
        cout << "Distances are not equal" << endl;

    return 0;
}