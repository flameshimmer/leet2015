// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include <windows.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;


// Solution 1 main entries
namespace Solution1
{
	void TwoSum();
	void ThreeSum();





};


// Helper functions
bool compare_STB(int i, int j);
bool compare_BTS(int i, int j);
void print(vector<int> input);


// Template helper functions
template <class T>
vector<T> createVector(std::initializer_list<T> list)
{
	vector<T> myVector;
	for (auto elem : list)
	{
		myVector.push_back(elem);
	}
	return myVector;
}



