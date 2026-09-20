#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("students.txt");

    file << "Name: Tooba" << endl;
    file << "Roll No: 101" << endl;

    file << "Name: Uzma" << endl;
    file << "Roll No: 03" << endl;

    file << "Name: kiran" << endl;
    file << "Roll No: 02" << endl;

    file.close();
    ifstream readFile("students.txt");

    string line;

    cout << "Student Details:" << endl;

    while (getline(readFile, line))
    {
        cout << line << endl;
    }

    readFile.close();

    return 0;
}
