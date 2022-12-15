#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	vector <string> result;
	int n, num, den;

	do
	{
		system("cls");
		cout << "Enter n: ";
		cin >> n;
	} while (n < 5 || n>10);

	for (int i = 0; i < n; i++)
	{
		stringstream builder;

		cout << "Enter numerator " << i + 1 << ": ";
		cin >> num;

		cout << "Enter denominator " << i + 1 << ": ";
		cin >> den;

		builder << num << "/" << den;
		result.push_back(builder.str());
	}

	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
			cout << result[i] << ", ";
		else
			cout << result[i] << ".\n";
	}
}