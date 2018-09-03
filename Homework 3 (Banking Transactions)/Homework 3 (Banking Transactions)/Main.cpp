#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void main()
{
	ifstream fin;
	fin.open("bank.dat");
	int accountnumber, code, depositcount = 0, withdrawlcount = 0;
	float amount, balance, depositbalance, withdrawlbalance, totaldeposit = 0, totalwithdrawl = 0, fee = 10.00, minimumbalance = 100.00;
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "[Acc #]" << setw(12) << "[Balance:]" << setw(28) << "[Notes:]" << endl << endl;
	fin >> accountnumber >> code >> amount >> balance;
	while (!fin.eof())
	{
		if (code == 1)
		{
			depositbalance = balance + amount;
			cout << setw(6) << accountnumber << setw(4) << "$" << setw(9) << depositbalance << endl;
			totaldeposit = totaldeposit + amount;
			depositcount++;
		}
		else
		{
			if (code == 2 && amount <= balance)
			{
				withdrawlbalance = balance - amount;
				cout << setw(6) << accountnumber << setw(4) << "$" << setw(9) << withdrawlbalance << endl;
				totalwithdrawl = totalwithdrawl + amount;
				withdrawlcount++;
			}
			if (code == 2 && amount > balance)
			{
				cout << setw(6) << accountnumber << setw(13) << "FAILED!" << setw(48) << "Insufficient Funds!" << endl;
			}
			if (code == 2 && withdrawlbalance < minimumbalance)
			{
				withdrawlbalance = withdrawlbalance - fee;
				cout << setw(10) << "$" << setw(9) << withdrawlbalance << setw(48) << "Balance below minimum -- $10.00 fee assessed!" << endl;
			}
		}
		if (code > 2)
		{
			cout << setw(6) << accountnumber << setw(13) << "FAILED!" << setw(48) << "Bad Transaction Code!" << endl;
		}
		fin >> accountnumber >> code >> amount >> balance;
	}
	cout << endl << endl;
	cout << "Global Stats:" << endl;
	cout << "The total number of deposits made was:" << setw(2) << depositcount << "." << endl;
	cout << "The total dollar value of the deposits made was:" << setw(2) << "$" << setw(9) << totaldeposit << "." << endl;
	cout << "The total number of SUCCESSFUL withdrawls made was:" << setw(2) << withdrawlcount << "." << endl;
	cout << "The total dollar value of the SUCCESSFUL withdrawls made was:" << setw(2) << "$" << setw(8) << totalwithdrawl << "." << endl;
	system("pause");
}
