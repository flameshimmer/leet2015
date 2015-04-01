#include "stdafx.h"

//Implement next permutation, which rearranges numbers into the 
//lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as 
//the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and
//its corresponding outputs are in the right - hand column.
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1

namespace Solution1
{
	void swap(vector<int>& num, int i, int j)
	{
		int temp = num[i];
		num[i] = num[j];
		num[j] = temp;
	}

	void reverse(vector<int>& num, int start, int end)
	{
		while (start < end)
		{
			swap(num, start, end);
			start++;
			end--;
		}
	}

	void nextPermutation(vector<int> &num) 
	{
		int len = num.size();
		if (len < 2) { return; }

		int curValue = num[len-1];
		int i;
		for (i = len - 2; i >= 0; i--)
		{
			if (num[i] < curValue) { break; }
			curValue = num[i];
		}
		if (i >= 0)
		{
			int j;
			for (j = len - 1; j > i; j--)
			{
				if (num[j] > num[i]){ break; }
			}
			swap(num, i, j);
		}
		
		reverse(num, i + 1, len - 1);
	}

	void NextPermutation()
	{
		vector<int> num = createVector({ 1, 2, 3 });
		//nextPermutation(num);
		print(num);

		num = createVector({ 3, 2, 1 });
		//nextPermutation(num);
		print(num);

		num = createVector({ 1, 1, 5 });
		//nextPermutation(num);
		print(num);

		num = createVector({ 1, 2 });
		nextPermutation(num);
		print(num);

	}
}