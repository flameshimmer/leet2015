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
