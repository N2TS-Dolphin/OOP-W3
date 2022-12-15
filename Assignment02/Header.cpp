#include "Header.h"

void WriteFile(ofstream& out, vector <string> result)
{
	out.open("output.txt");

	if (!out.is_open())
	{
		cout << "ERROR!!!";
		return;
	}
	
	for (int i = 0; i < result.size(); i++)
	{
		out << result[i] << endl;
	}

	out.close();
}