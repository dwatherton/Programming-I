#include<iostream>
#include<fstream>
#include<iomanip> 
using namespace std;

void main()
{
	ofstream fout;
	float fahr, cent, sumf = 0, sumc = 0;
	int count = 0;
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(1);
	fout.open("Temps.out");
	fout << setw(25) << "Fahrenheit" << setw(15) << "Centigrade" << endl << endl;
	cout << "Temperature Convertor" << endl;
	cout << "Please enter a Fahrenheit temperature" << endl;
	cout << "Enter -99999 to quit" << endl;
	cin >> fahr;
	while (fahr != -99999)
	{
		cent = (5.0 / 9.0)*(fahr - 32);
		sumf = sumf + fahr, sumc = sumc + cent, count++;
		fout << setw(25) << fahr << setw(15) << cent << endl;
		cout << "Please enter a Fahrenheit temperature" << endl;
		cout << "Enter -99999 to quit" << endl;
		cin >> fahr;
	}
	fout << endl << "Average" << setw(18) << sumf / count << setw(15) << sumc / count << endl;
	system("pause");
}