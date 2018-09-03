#include<iostream>
#include<iomanip>
using namespace std;

void main()
{
	int number;
	cout << setw(5) << "Num" << setw(12) << "Char" << endl;
	for (number = 32; number <= 255; number++)
	{
		cout << setw(5) << number << setw(5) << "|" << setw(5) << (char)number << endl;
	}
	system("pause");
}