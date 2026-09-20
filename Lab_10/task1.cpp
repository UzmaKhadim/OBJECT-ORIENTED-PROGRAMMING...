#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream writeFile("notes.txt");

    writeFile << "Welcome to OOP File handling lab." << endl;
    writeFile << "File handling is important." << endl;
    writeFile << "we had studied OOP but still we dont have concpets." << endl;

    writeFile.close();
    ifstream readFile("notes.txt");
    string line;

    cout << "File Contents:" << endl;

    while (getline(readFile, line))
    {
        cout << line << endl;
    }

    readFile.close();
    ofstream appendFile("notes.txt", ios::app);

    appendFile << "Name:Uzma" << endl;
    appendFile << "Roll No: 1245" << endl;

    appendFile.close();

    cout << "\nData appended successfully." << endl;

    return 0;
}
