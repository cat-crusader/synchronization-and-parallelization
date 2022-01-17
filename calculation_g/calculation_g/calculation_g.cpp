// calculation_g.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <Windows.h>

#include "./../../testing/trialfuncs.hpp"

using namespace std;

long long getResult(const string& answer)
{
	long long result = 0;
	for (size_t i = 4; i < answer.size() - 1; i++)
		result = result * 10 + (answer[i] - '0');
	return result;
}

int main()
{
	//cout << "Calculation g(x) started" << endl << endl;
	MSG a;
	while (!PeekMessage(&a, NULL, 0, 0, PM_REMOVE)) {};
	int x = a.lParam;
	DWORD ui_process_thread_id = a.wParam;
	//cout << "Get message: " << x << endl << endl;
	//cout << "The sender is: " << ui_process_thread_id << endl << endl;
	stringstream s;
	int n = 1;
	while (n < 100)
	{
		s << os::lab1::compfuncs::trial_g<os::lab1::compfuncs::AND>(x);
		if (s.str() == "hard fail")
		{
			PostThreadMessage(ui_process_thread_id, NULL, n, 3);
			return 0;
		}
		else if (s.str() != "soft fail")
		{
			if (!PostThreadMessage(ui_process_thread_id, getResult(s.str()) + 2, n, 1))
			{
				cout << "PostMessage failed " << GetLastError() << endl;
			}
			return 0;
		}
		PostThreadMessage(ui_process_thread_id, NULL, n, 5);
		n++;
		s.clear();
	}
	cout << "Calculation g finished" << endl << endl;
	PostThreadMessage(ui_process_thread_id, NULL, n, 2);

	return 0;
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
