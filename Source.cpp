#include <iostream>
using namespace std;

int input();
void createSquare(unsigned int n);

//Main func.

void main()
{
	unsigned int n = input();
	createSquare(n);
}

//User number input func.

int input()
{
	unsigned int n = 0;
	cout << "Enter any positive number up to 10: ";
	cin >> n;
	cout << endl;

	if (n < 1 || n > 10)
	{
		cout << "Incorrect input" << endl;
		return input();
	}
	else
		return n;
}

//Square creation func.

void createSquare(unsigned int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 || i == n || j == 1 || j == n)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	
	n--;
	cout << endl;

	if (n > 1)
	{
		createSquare(n);
	}
}