// Leet2015.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
typedef std::numeric_limits< double > dbl;

int _tmain(int argc, _TCHAR* argv[])
{
	// Runtime begin marker start
	clock_t begin = clock();


	//Solution1::TwoSum();
	//Solution1::ThreeSum();
	//Solution1::ThreeSumClosest();
	//Solution1::FourSum();

	//Solution1::AddTwoNumbers();
	//Solution1::AddBinary();
	
	//Solution1::Anagrams();
	
	//Solution1::LongestSubStringWithoutRepeatingCharacters();
	//Solution1::LongestPalindromeSubString();
	//Solution1::LongestCommonPrefix();
	//Solution1::LongestValidParentheses();
	//Solution1::LongestConsecutiveSequence();

	//Solution1::SearchInRotatedSortedArray();
	//Solution1::SearchInRotatedSortedArrayII();
	
	//Solution1::ReverseInteger();
	//Solution1::ReverseBits();
	//Solution1::ReverseWordsInAString();
	//Solution1::ReverseWordsInAStringII();
	//Solution1::ReverseLinkedListII();
	//Solution1::ReverseNodesInKGroup();

	//Solution1::RomanToInteger();
	//Solution1::IntegerToRoman();

	//Solution1::WordBreak();
	//Solution1::WordBreakII();

	//Solution1::NumberOf1Bits();
	//Solution1::PlusOne();
	//Solution1::ZigZagConversion();
	//Solution1::FactorialTrailingZeroes();

	//Solution1::PascalsTriangle();
	//Solution1::PascalsTriangleII();

	//Solution1::LinkedListCycle();
	//Solution1::LinkedListCycleII();

	//Solution1::RotateArray();
	//Solution1::RotateImage();
	//Solution1::RotateList();

    //Solution1::FirstMissingPositive();
	//Solution1::FindMinimumInRotatedSortedArray();
	//Solution1::FindMinimumInRotatedSortedArrayII();
	//Solution1::UniquePaths();
	//Solution1::UniquePathsII();
	//Solution1::DecodeWays();
	//Solution1::EditDistance();
	//Solution1::MaximumSubarray();
	//Solution1::Combinations();
	//Solution1::CombinationSum();
	//Solution1::CombinationSumII();
	//Solution1::MedianOfTwoSortedArrays();
	//Solution1::PalindromeNumber();
	//Solution1::StringToInteger();
	//Solution1::LetterCombinationsOfAPhoneNumber();
	//Solution1::RemoveNthNodeFromEndOfList();
	//Solution1::SingleNumber();
	Solution1::SingleNumberII();



	// Runtime end marker
	clock_t end = clock();
	double elapsed_time_in_millisecond = double(end - begin) / double(CLOCKS_PER_SEC / 1000.0);
	
	// End program routine
	cout.precision(dbl::digits10);
	cout << "\n\nYour program total runtime is: " << elapsed_time_in_millisecond << "ms";
	cout << "\n\nPress any key to exit ...\n\n";
	cin.get();	
	return 0;
}

