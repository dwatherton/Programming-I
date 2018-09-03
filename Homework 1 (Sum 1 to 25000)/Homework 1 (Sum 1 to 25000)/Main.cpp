#include<iostream>
using namespace std;

void main()
{
	int k, sum = 0;
	for (k = 0; sum <= 25000;)
	{
		k = k + 1;
		sum = sum + k;
	}
	cout << "The last number added was " << k << "." << endl;
	cout << "The final sum was " << sum << "." << endl;
	system("pause");
}