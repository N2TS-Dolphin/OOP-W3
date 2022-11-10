#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

#include "Utils.h"

class Fraction
{
public:
	inline static const string PATTERN = "\\d+/\\d+";
private:
	int _num;
	int _den;
public:
	Fraction();
	Fraction(int, int);
	int setNum() const { return _num; }
	int setDen() const { return _den; }
	string toString();
public:
	static Fraction parse(string data);
};

Fraction::Fraction()
{
	_num = 0;
	_den = 1;
}

Fraction::Fraction(int num, int den)
{
	this->_num = num;
	this->_den = den;
}

string Fraction::toString()
{
	stringstream builder;
	builder << _num << "/" << _den;

	string result = builder.str();
	return result;
}

Fraction Fraction::parse(string data)
{
	int num = 0;
	int den = 1;

	auto tokens = Utils::String::split(data, "/");
	num = stoi(tokens[0]);
	den = stoi(tokens[1]);

	Fraction result(num, den);
	return result;
}

class ConvertFractions
{
public:
	string FractionConvert(const Fraction& f)
	{
		stringstream builder;

		int num = f.setNum();
		int den = f.setDen();
		builder << num << "/" << den;

		string result = builder.str();
		return result;
	}

	string FractionLowestTermConvert(const Fraction& f)
	{
		stringstream builder;

		int gcd = Utils::Integer::gcd(f.setNum(), f.setDen());

		if (f.setNum() % f.setDen() == 0)
		{
			builder << f.setNum() / f.setDen();
		}
		else if (f.setNum() > f.setDen())
		{
			int tmp = f.setNum() / f.setDen();
			int num = f.setNum() % f.setDen();
			int den = f.setDen();

			builder << tmp << " " << num << "/" << den;
		}
		else
		{
			int num = f.setNum() / gcd;
			int den = f.setDen() / gcd;
			builder << num << "/" << den;
		}

		string result = builder.str();
		return result;
	}

	string FractionDecimalConvert(const Fraction& f)
	{
		stringstream builder;

		int decimal = f.setNum() / f.setDen();
		int tmp = f.setNum() % f.setDen() / (float)f.setDen() * 100;

		if (tmp < 10)
			builder << decimal << "." << tmp << "0";
		else
			builder << decimal << "." << tmp;

		string result = builder.str();
		return result;
	}

	string FractionPercentConvert(const Fraction& f)
	{
		stringstream builder;

		int decimal = (f.setNum() / f.setDen());
		int tmp = f.setNum() % f.setDen() / (float)f.setDen() * 100;
		if (decimal != 0)
		{
			if (tmp < 10)
				builder << decimal << tmp << "0%";
			else
				builder << decimal << tmp << "%";
		}
		else
		{
			if (tmp < 10)
				builder << tmp << "0%";
			else
				builder << tmp << "%";
		}


		string result = builder.str();
		return result;
	}
};

int main()
{
	string input = "Fraction.txt";
	ifstream reader(input, ios::in);

	string buffer;
	getline(reader, buffer);
	int count = stoi(buffer);

	cout << "Expecting to get " << count << " frations" << endl;
	vector<Fraction> a;

	for (int i = 0; i < count; i++)
	{
		getline(reader, buffer);
		regex pattern(Fraction::PATTERN);

		if (regex_match(buffer, pattern))
		{
			Fraction f = Fraction::parse(buffer);
			a.push_back(f);
		}
		else
		{
			// Do not things
		}
	}

	ConvertFractions converter;

	cout << "Found " << a.size() << " fractions: ";
	for (int i = 0; i < a.size(); i++)
	{
		string message = converter.FractionConvert(a[i]);

		if (i == a.size() - 1)
			cout << message << ".\n";
		else
			cout << message << ", ";
	}

	cout << "Lowest Term: ";
	for (int i = 0; i < a.size(); i++)
	{
		string message = converter.FractionLowestTermConvert(a[i]);

		if (i == a.size() - 1)
			cout << message << ".\n";
		else
			cout << message << ", ";
	}

	cout << "Decimal: ";
	for (int i = 0; i < a.size(); i++)
	{
		string message = converter.FractionDecimalConvert(a[i]);

		if (i == a.size() - 1)
			cout << message << ".\n";
		else
			cout << message << ", ";
	}

	cout << "Percent: ";
	for (int i = 0; i < a.size(); i++)
	{
		string message = converter.FractionPercentConvert(a[i]);

		if (i == a.size() - 1)
			cout << message << ".\n";
		else
			cout << message << ", ";
	}

	cout << endl << endl << 9 % 5;

	reader.close();
}