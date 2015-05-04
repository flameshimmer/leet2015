#include "stdafx.h"

//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//1         3     3      2      1
// \       /     /      / \      \
//  3     2     1      1   3      2
// /     /       \                 \
//2     1         2                 3

namespace Solution1
{
	int numTrees(int n)
	{
		vector<int>count(n + 1, 0);
		count[0] = 1;
		count[1] = 1;

		for (int i = 2; i <= n; i++) // i is the count of the tree
		{
			for (int j = 0; j < i; j++) // j is the node on the left side of the tree
			{
				count[i] += count[j] * count[i - j - 1];
			}			
		}
		return count[n];
	}

	namespace other
	{
		int countTree(int startVal, int endVal, unordered_map<int, int>& map)
		{
			if (endVal <= startVal) { return 1; }
			if (map.count(endVal - startVal) != 0) { return map[endVal - startVal]; }
			else{
				int result = 0;
				for (int i = startVal; i <= endVal; i++)
				{
					int leftCount = countTree(startVal, i - 1, map);
					int rightCount = countTree(i + 1, endVal, map);
					result += leftCount * rightCount;
				}
				map[endVal - startVal] = result;
				return result;
			}
		}

		int numTrees(int n)
		{
			unordered_map<int, int> map;
			return countTree(1, n, map);
		}
	}


	void UniqueBinarySearchTrees()
	{
		print(numTrees(13));
	}
}