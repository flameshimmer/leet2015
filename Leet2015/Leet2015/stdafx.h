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
#include <string>
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cMath>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <map>
using namespace std;


// Solution 1 main entries
namespace Solution1
{
	void TwoSum();
	void ThreeSum();
	void ThreeSumClosest();
	void FourSum();
	
	void AddTwoNumbers();
	void AddBinary();

	void Anagrams();
	void LongestSubStringWithoutRepeatingCharacters();
	void LongestPalindromeSubString();
	void LongestCommonPrefix();
	void LongestValidParentheses();
	void LongestConsecutiveSequence();
	
	void SearchInRotatedSortedArray();
};


// Helper functions
bool compare_STB(int i, int j);
bool compare_BTS(int i, int j);
void print(vector<int> input);
void print(vector<vector<int>> input);
void print(int input);

void print(vector<string> input);
void print(string input);


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


// helper class
// List Node
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* createList(initializer_list<int> list);
void deleteList(ListNode* list);
void print(ListNode* list);


