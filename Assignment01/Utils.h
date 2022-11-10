#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace Utils 
{
	class String 
	{
	public:
		static auto split(string haystack, string needle) 
		{
			vector<string> result;

			int startPos = 0;
			size_t foundPos = haystack.find(needle, startPos);

			while (foundPos != string::npos) 
			{
				int count = foundPos - startPos;
				string token = haystack.substr(startPos, count);
				result.push_back(token);

				startPos = foundPos + needle.length();
				foundPos = haystack.find(needle, startPos);
			}

			// Remaining substring
			string token = haystack.substr(startPos, haystack.length() - startPos);
			result.push_back(token);

			return result;
		}
	};

	class Integer 
	{
	public:
		// Greatest common divisor
		static int gcd(int a, int b) 
		{
			int result = min(a, b); // Find Minimum of a nd b
			while (result > 0) 
			{
				if (a % result == 0 && b % result == 0) 
				{
					break;
				}
				result--;
			}
			return result; // return gcd of a nd b
		}
	};
}