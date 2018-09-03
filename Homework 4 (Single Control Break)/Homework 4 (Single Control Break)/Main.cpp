#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void main()
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	ifstream fin;
	fin.open("quizzes.dat");
	int studentid, score, startid, highscore, lowscore, totalscore = 0, count = 0;
	double average;
	fin >> studentid >> score;
	startid = studentid;
	highscore = score;
	lowscore = score;
	cout << "[Id]" << setw(13) << "[Average]" << endl;
	while (!fin.eof())
	{
		if (studentid == startid)
		{
			totalscore = totalscore + score;
			count++;

			if (score > highscore)
			{
				highscore = score;
			}
			if (score < lowscore)
			{
				lowscore = score;
			}
		}

		else
		{
			average = (totalscore - highscore - lowscore) / (count - 2.0);
			cout << startid << setw(10) << average << endl;

			startid = studentid;
			highscore = score;
			lowscore = score;
			totalscore = score;
			count = 1;
		}
		fin >> studentid >> score;
	}
	average = (totalscore - highscore - lowscore) / (count - 2.00);
	cout << studentid << setw(10) << average << endl;
	system("pause");
}