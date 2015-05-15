#include "stdafx.h"

// 
namespace Solution1
{


	int minCut(string s) {
		int len = s.size();
		vector<int>D(len + 1);
		for (int i = 0; i < len + 1; i++)
		{
			D[i] = len - 1 - i;
		}
		vector<vector<bool>> P(len, vector<bool>(len, false));

		for (int i = len - 1; i >= 0; i--)
		{
			for (int j = i; j < len; j++)
			{
				if (s[i] == s[j] && (j - i < 2 || P[i + 1][j - 1]))
				{
					P[i][j] = true;
					D[i] = min(D[i], D[j + 1] + 1);
				}
			}
		}

		return D[0];
	}

	void PalindromePartitioningII()
	{
		print(minCut(string("aab")));
	}
}