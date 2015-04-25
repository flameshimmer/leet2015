#include "stdafx.h"

//The set[1, 2, 3, …, n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence(ie, for n = 3) :
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.
//
//Note: Given n will be between 1 and 9 inclusive.

namespace Solution1
{
	string getPermutation(int n, int k) 
	{
		int permCount = 1;
		vector<int> nums(n, 0);
		for (int i = 0; i < n; i++)
		{
			nums[i] = i + 1;
			permCount *= i+1;
		}
		k--;
		string result;
		for (int i = 0; i < n; i++)
		{
			permCount /= n - i;
			int index = k / permCount;
			result.push_back(nums[index] + '0');			
			for (int j = index; j < n-1; j++)
			{
				nums[j] = nums[j + 1];
			}
			k = k % permCount;
		}
		return result;
	}

	void PermutationSequence()
	{
		print(getPermutation(3, 5));
	}
}