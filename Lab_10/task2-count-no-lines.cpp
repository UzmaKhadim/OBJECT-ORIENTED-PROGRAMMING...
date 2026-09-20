#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("notes.txt");

    string line;
    int lineCount = 0;

    while (getline(file, line))
    {
        lineCount++;
    }

    file.close();

    cout << "Total number of lines: " << lineCount << endl;

    return 0;
}