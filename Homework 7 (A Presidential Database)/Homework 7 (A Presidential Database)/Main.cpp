#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

void main()
{
	struct { int chronum; string pname; int next; } plist[60], temp;
	int n = 0, bottom, maxindex, i;
	fstream fin;
	fin.open("prez.dat");
	fin >> plist[n].pname;
	while (!fin.eof())
	{
		plist[n].chronum = n + 1;
		n++;
		fin >> plist[n].pname;
	}
	plist[n - 1].next = -1;

	for (bottom = n - 1; bottom > 0; bottom--)
	{
		maxindex = 0;
		for (i = 1; i <= bottom; i++)
		{
			if (plist[i].pname > plist[maxindex].pname)
			{
				maxindex = i;
			}
		}
		temp = plist[maxindex];
		plist[maxindex] = plist[bottom];
		plist[bottom] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (plist[i].chronum == plist[j].chronum - 1)
			{
				plist[i].next = j;
			}
		}
	}

	cout << setw(8) << "location" << setw(10) << "chronum  " << left << setw(22) << "president's name" << right << setw(7) << "next prez" << endl << endl;
	for (i = 0; i <= n - 1; i++)
	{
		cout << setw(8) << i << setw(8) << plist[i].chronum << "  " << left << setw(22) << plist[i].pname << right << setw(9) << plist[i].next << endl;
	}

	system("pause");
}