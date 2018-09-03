#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

void main()
{
	ofstream fout;
	ifstream ftests, fans;
	string answers, id, responses;
	int numstudents = 0, numcorrect, counter[20][5] = { 0 };
	ftests.open("tests.dat");
	fans.open("answers.dat");
	fout.open("table.dat");
	fans >> answers;
	fout << setw(11) << "student-id" << setw(20) << "number correct" << endl << endl;
	ftests >> id >> responses;
	while (!ftests.eof())
	{
		numstudents++;
		numcorrect = 0;
		for (int i = 0; i < 20; i++)
		{
			counter[i][responses[i] - 'A']++;
			if (responses[i] == answers[i])
			{
				numcorrect++;
			}
		}
		fout << id << setw(20) << numcorrect << endl;
		ftests >> id >> responses;
	}
	fout << endl << endl;
	fout << "number of students taking exam = " << numstudents << endl;
	fout << endl << endl << endl;
	fout << setw(8) << "question" << setw(5) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << endl << endl;
	for (int j = 0; j < 20; j++)
	{
		fout << setw(8) << j + 1 << setw(5);
		for (int k = 0; k < 5; k++)
		{
			fout << setw(5) << counter[j][k];
			if (k == answers[j] - 'A')
			{
				fout << "*";
			}
			else
			{
				fout << " ";
			}
		}
		fout << endl;
	}
}