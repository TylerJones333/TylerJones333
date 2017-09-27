#include<iostream>
#include<iomanip> 
using namespace std;

struct Raise
{
	char name[20], department[20];
	float CurrentYearlyIncome, RaisePercentage, RaiseAmount, NewPayAmount;
	float TotalCurrentIncomes, TotalRaiseAmounts, TotalNewPayAmounts;
};

void getinfo(struct Raise r[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			cin.ignore(20, '\n');
			cout << endl;
		}
		cout << "Enter employee name	";
		cin.getline(r[i].name, 20);
		cout << "Enter department	";
		cin.getline(r[i].department, 20);
		cout << "Enter Current Yearly Income: $	";
		cin >> r[i].CurrentYearlyIncome;
	}
	
}

void determineraise(struct Raise r[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (r[i].CurrentYearlyIncome >= 90000.01)
			r[i].RaisePercentage = 5.1;
		else 
			if (90000 >= r[i].CurrentYearlyIncome >= 800000.01)
				r[i].RaisePercentage = 5.9;
			else
				if (80000 >= r[i].CurrentYearlyIncome >= 700000.01)
					r[i].RaisePercentage = 7.2;
				else
					r[i].RaisePercentage = 8.5;
	}
}

void calc(struct Raise r[], int n)
{
	r[1].TotalCurrentIncomes = 0;
	r[1].TotalRaiseAmounts = 0;
	r[1].TotalNewPayAmounts = 0;

	for (int i = 0; i < n; i++)
	{
		r[i].RaiseAmount = r[i].CurrentYearlyIncome * (r[i].RaisePercentage / 100);
		r[i].NewPayAmount = r[i].CurrentYearlyIncome + r[i].RaiseAmount;

		r[1].TotalCurrentIncomes = r[1].TotalCurrentIncomes + r[i].CurrentYearlyIncome;
		r[1].TotalRaiseAmounts = r[1].TotalRaiseAmounts + r[i].RaiseAmount;
		r[1].TotalNewPayAmounts = r[1].TotalNewPayAmounts + r[i].NewPayAmount;
	}
}

void printinfo(struct Raise r[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Name: " << r[i].name << endl;
		cout << "Department: " << r[i].department << endl;
		cout << setprecision(2) << showpoint << fixed;
		cout << "Current Yearly Income: $ " << r[i].CurrentYearlyIncome << endl;
		cout << "Raise Percentage: " << r[i].RaisePercentage << "%" << endl;
		cout << "Raise Amount: $ " << r[i].RaiseAmount << endl;
		cout << "New Pay Amount: $ " << r[i].NewPayAmount << endl << endl;
	}
	cout << "The total of the current yearly incomes is: $ " << r[1].TotalCurrentIncomes << endl;
	cout << "The total of the raise amounts is: $ " << r[1].TotalRaiseAmounts << endl;
	cout << "The total of the new pay amounts is: $ " << r[1].TotalNewPayAmounts << endl;
}

int main()
{
	Raise r[5];
	getinfo(r, 5);
	determineraise(r, 5);
	calc(r, 5);
	printinfo(r, 5);
	system("PAUSE");
	return 0;
}