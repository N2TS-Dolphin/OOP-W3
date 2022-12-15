#include "Header.h"
#include "IntegerGenerator.h"

int main()
{
	ofstream out;
	IntegerGenerator* intGen = IntegerGenerator::instance();
	vector <string> result;
	int n = intGen->next(5, 10);
	
	for (int i = 0; i < n; i++)
	{
		stringstream builder;
		builder << intGen->next(10, 100) << "/" << intGen->next(10, 100);
		result.push_back(builder.str());
	}

	cout << "Generating " << n << " fractions: ";
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
			cout << result[i] << ", ";
		else
			cout << result[i] << ".\n";
	}

	cout << "Writing all " << n << " fractions into output.txt file.\n";

	WriteFile(out, result);
}