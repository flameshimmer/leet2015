#include "stdafx.h"


bool compare_STB(int i, int j)
{
	return i < j;
}

bool compare_BTS(int i, int j)
{
	return i > j;
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

void print(vector<vector<int>> input)
{
	for (vector<int> i : input)
	{
		print(i);
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