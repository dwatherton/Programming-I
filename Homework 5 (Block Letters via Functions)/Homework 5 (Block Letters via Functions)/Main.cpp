#include<iostream>
#include<fstream>
using namespace std;

ifstream fin;
ofstream fout;

void line(char ch, int num)
{
	for (int i = 1; i <= num; i++)
	{
		fout << ch;
	}
	fout << endl;
}

void rectangle(char ch, int rows, int columns)
{
	for (int j = 1; j <= rows; j++)
	{
		line(ch, columns);
	}
}

void main()
{
	char ch;
	int letterinword = 0, placeinalphabet;
	fin.open("animals.dat");
	fout.open("zoo.txt");
	fin.get(ch);

	while (!fin.eof())
	{
		if (ch == '\n')
		{
			letterinword = 0;
			fout << endl << endl << endl << endl << endl << endl << endl;
		}
		else
		{
			letterinword++;
			placeinalphabet = ch - 'A' + 1;
			rectangle(ch, letterinword, placeinalphabet);
			fout << endl;
		}
		fin.get(ch);
		placeinalphabet = 0;
	}
}