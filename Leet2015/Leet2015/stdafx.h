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
#include <queue> // for priority queue

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
#include <queue>
#include <map>
#include <stdint.h>
using namespace std;

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

template <class T>
void print(vector<vector<T>> input)
{
	cout << "\nMatrix: \n";
	if (input.size() == 0) { cout << "Empty!!! \n"; return; }
	string div = "";
	for (unsigned int i = 0; i < input[0].size(); i++)
	{
		div += "-----";
	}
	div += '-';
	cout << div << "\n";
	for (vector<T> v : input)
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{
			cout << "| " << setw(2) << v[i] << " ";
		}
		cout << "|\n";
		cout << div << "\n";
	}
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

// RandomListNode
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

// Helper functions
// int
bool compare_STB(int i, int j);
bool compare_BTS(int i, int j);
void print(int input[], int len);
void print(vector<int> input);
void print(int input);

// unsigned int
void print(uint32_t input);

// boolean
void print(bool input);

// string
void print(vector<string> input);
void print(string input);
void printWithSpace(string input);

// intervals
void print(vector<Interval> input);

// bits
void printBits(uint32_t input);

// matrix
void printStringMatrix(vector<string>board);
vector<vector<char>> createMatrix(string rawInput[], int size);

// tree
TreeNode* createTree(string data, int& index);

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
	void ValidParentheses();
	void ValidPalindrome();

	// helper functions across problems
	void ValidSudoku();
	bool isValidSudoku(vector<vector<char> > &board);

	// 3/27/2015, 3/28/2015
	void SudokuSolver();

	// 3/29/2015
	void RegularExpressionMatching();
	void WildcardMatching();
	void MinimumPathSum();
	void Triangle();
	
	// 3/30/2015
	void InterleavingString();
	void MergeTwoSortedLists();
	void MergeKSortedLists();
	void GenerateParentheses();
	
	// 3/31/2015
	void SwapNodesInPairs();
	void RemoveDuplicatesFromSortedArray();
	void RemoveElement();
	void DivideTwoIntegers();

	// 4/1/2015
	void RemoveDuplicatesfromSortedList();
	void NextPermutation();
	void CountAndSay();
	void LengthOfLastWord();

	// 4/2/2015
	void RemoveDuplicatesFromSortedListII();
	void PartitionList();
	void SortList();
	void ReorderList();
	void IntersectionOfTwoLinkedLists();

	//4/5/2015
	void InsertionSortList();
	void ZigZagConversion();
	void ContainerWithMostWater();
	void ImplementStrStr(); // ** missing kmp solve
	void Permutation();
	void PermutationII();
	void Pow();

	//4/6/2015
	void Subsets();
	void SubsetsII();
	void GrayCode();

	//4/7/2015
	void CopyListWithRandomPointer();
	void ConvertSortedListToBinarySearchTree();
	void SearchForARange();

	//4/8/2015
	void MergeSortedArray();

	//4/14/2015
	void MajorityElement();
	void ExcelSheetColumnNumber();
	void ExcelSheetColumnTitle();

	//4/15/2015
	void CompareVersionNumbers();
	void SearchInsertionPosition();
	void SubstringWithConcatenationOfAllWords();

	//4/19/2015
	void ClimbingStairs();
	void MaximalRectangle();
	void LargestRectangleInHistogram();
	void TrappingRainWater();
	void BitwiseAndOfNumbersRange();

	//4/20/2015
	void MultiplyStrings();
	void JumpGame();
	void JumpGameII();

	//4/21/2015
	void NQueens();
	void NQueensII();
	void HouseRobber();

	// 4/22/2015
	void SpiralMatrix();
	void SpiralMatrixII();
	void Sqrt();

	// 4/23/2015
	void MergeIntervals();
	
	// 4/25/2015
	void InsertInterval();
	void PermutationSequence();
	void SetMatrixZeroes();
	void RemoveLinkedListElements();
	void PathSum();
	void MaximumDepthOfBinaryTree();
	void MinimumDepthOfBinaryTree();
	void SymmetricTree();   // need iterative solve

	// 4/26/2015
	void ValidNumber();
	void TextJustification();
	void SimplifyPath();
	void SearchA2DMatrix();
	void SortColors();

	//4/28/2015
	void WordSearch();
	void RemoveDuplicatesFromSortedArrayII();
	void RestoreIPAddresses();

	//4/29/2015
	void UniqueBinarySearchTrees(); // didn't work
	void BalancedBinaryTree();
	void BinaryTreeLevelOrderTraversal();
	void BinaryTreeLevelOrderTraversalII();
	void PathSumII();

	//4/30/2015
	void BinarySearchTreeIterator();
	void SumRootToLeafNumbers();
	void BinaryTreePreorderTraversal();
	void FlattenBinaryTreeToLinkedList();
	void BinaryTreeZigzagLevelOrderTraversal();
	void BinaryTreeUpsideDown();

	//5/2/2015
	void ConstructBinaryTreeFromPreorderAndInorderTraversal();
	void ConstructBinaryTreeFromInorderAndPostorderTraversal();
	void BinaryTreeRightSideView();
};
