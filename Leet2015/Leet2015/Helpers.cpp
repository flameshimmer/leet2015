#include "stdafx.h"


bool compare_STB(int i, int j)
{
	return i < j;
}

bool compare_BTS(int i, int j)
{
	return i > j;
}

void print(int input[], int len)
{
	cout << "\nInteger array: \n";
	for (int i = 0; i < len - 1; i++)
	{
		cout << input[i] << ", ";
	}
	cout << input[len - 1] << "\n";
}

void print(vector<int> input)
{
	cout << "\nVector: ";
	int inputSize = input.size();
	if (inputSize == 0) {
		cout << "\n";
		return; 
	}

	for (int i = 0; i < inputSize - 1; i++)
	{
		cout << input[i] << ",";
	}
	cout << input[inputSize - 1] << "\n";
}

void print(vector<string> input)
{
	cout << "\nString Vector: ";
	int inputSize = input.size();
	if (inputSize == 0) {
		cout << "\n";
		return;
	}

	for (int i = 0; i < inputSize - 1; i++)
	{
		cout << input[i] << "\n";
	}
	cout << input[inputSize - 1] << "\n";
}

void print(vector<vector<int>> input)
{
	cout << "\nMatrix: \n";
	string div = "";
	for (unsigned int i = 0; i < input[0].size(); i++)
	{
		div += "-----";
	}
	div += '-';
	cout << div << "\n";
	for (vector<int> v : input)
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{			
			cout << "| " << setw(2) << v[i] << " ";
		}
		cout << "|\n";
		cout << div << "\n";
	}
}

void print(int input)
{
	cout << "integer: " << input << "\n";
}

void print(string input)
{
	cout << "string: " << input << "\n";
}

void printWithSpace(string input)
{
	cout << "string with space: \n";
	for (char c : input)
	{
		if (c == ' ') { c = '.'; }
		cout << c;
	}
	cout << "\n";
}

void print(uint32_t input)
{
	cout << "Unsigned 32 bits integer: " << input << "\n";
}

void print(bool input)
{
	cout << "\nBoolean: " << (input ? "true" : "false") << "\n";
}

void printBits(uint32_t input)
{
	cout << "Binary: \n";
	for (int i = 31; i >=0; i--)
	{
		if (input & (1 >> i))
		{
			cout << "1 ";
		}
		else
		{
			cout << "0";
		}
	}
	cout << "\n";
}
