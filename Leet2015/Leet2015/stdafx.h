// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include <limits> // for printing double
#include <complex> // for math abs

#include <windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <initializer_list>
#include <cMath>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <map>
#include <stdint.h>
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
	void SearchInRotatedSortedArrayII();

	void ReverseInteger();
	void ReverseBits();
	void ReverseWordsInAString();
	void ReverseWordsInAStringII();
	void ReverseLinkedListII();
	void ReverseNodesInKGroup();

	void RomanToInteger();
	void IntegerToRoman();

	void WordBreak();
	void WordBreakII();

	void NumberOf1Bits();
	void PlusOne();
	void ZigZagConversion();
	void FactorialTrailingZeroes();

	void PascalsTriangle();
	void PascalsTriangleII();

	void LinkedListCycle();
	void LinkedListCycleII();

	void RotateArray();
	void RotateImage();
	void RotateList();
	void FirstMissingPositive();
	
	void FindMinimumInRotatedSortedArray();
	//3/21/2015
	void FindMinimumInRotatedSortedArrayII();
	
	void UniquePaths();
	void UniquePathsII();
	void DecodeWays();

	// 3/22/2015
	void EditDistance();
	void MaximumSubarray();
	void Combinations();

	// 3/23/2015
	void CombinationSum();
	void CombinationSumII();

	// 3/24/2015
	void MedianOfTwoSortedArrays(); //***

	// 3/25/2015
	void PalindromeNumber();
	void StringToInteger();
	void LetterCombinationsOfAPhoneNumber();
	void RemoveNthNodeFromEndOfList();
	void SingleNumber();
	
	// 3/26/2015
	void SingleNumberII();
};


// Helper functions
// int
bool compare_STB(int i, int j);
bool compare_BTS(int i, int j);
void print(int input[], int len);
void print(vector<int> input);
void print(vector<vector<int>> input);
void print(int input);

// unsigned int
void print(uint32_t input);

// boolean
void print(bool input);

// string
void print(vector<string> input);
void print(string input);
void printWithSpace(string input);

// bits
void printBits(uint32_t input);


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
ListNode* getListNodeAt(ListNode* list, int index);
ListNode* getLastNode(ListNode* list);
void deleteList(ListNode* list);
void print(ListNode* list);
ListNode* createListWithCycle(initializer_list<int> listValue, int indexPointFrom, int indexPointTo);


