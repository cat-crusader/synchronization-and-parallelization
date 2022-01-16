// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <sstream>
#include <conio.h>


using namespace std;

int enterNumber(const string& number)
{
    istringstream date_stream(number);
    bool number_is_correct = true;
    int new_number;
    number_is_correct = number_is_correct && (date_stream >> new_number);
    number_is_correct = number_is_correct && date_stream.eof();

    if (!number_is_correct)
    {
        throw logic_error("Wrong number format: " + number);
    }
    return new_number;
}

int getParametrs()
{
    while (true)
    {
        cout << "Enter number" << endl;
        string line;
        getline(cin, line);
        try
        {
            return enterNumber(line);
        }
        catch (exception e)
        {
            cout << e.what() << endl;
            cout << "Try again." << endl << endl;
        }
    }
}
int main()
{
    std::cout << "Hello World!\n";
    while (true) {
        cout << "Press any key to start program" << endl<<"Press esc to close program"<<endl;
        if (_getch() == 27) {// ESC button, ends program
            return 0;
        }
        else {

        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
