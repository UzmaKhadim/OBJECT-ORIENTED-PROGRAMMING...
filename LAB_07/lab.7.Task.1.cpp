#include <iostream>
using namespace std;
class Display {
private:
    int lastResult;

public:
    Display() {
        lastResult = 0;
    }

    void showResult(int result) {
        lastResult = result;
        cout << "Result: " << result << endl;
    }

    void showLastResult() {
        cout << "Last Result Shown: " << lastResult << endl;
    }
};
class Calculator {
private:
    Display display;   

public:
    void add(int a, int b) {
        int result = a + b;
        display.showResult(result);
    }

    void multiply(int a, int b) {
        int result = a * b;
        display.showResult(result);
    }

    void lastResult() {
        display.showLastResult();
    }
};
int main() {
    Calculator calc;

    calc.add(7, 3);
    calc.multiply(4, 2);

    calc.lastResult();

    return 0;
}
