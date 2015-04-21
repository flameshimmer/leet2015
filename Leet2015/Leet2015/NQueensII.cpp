#include "stdafx.h"

//Follow up for N - Queens problem.
//
//Now, instead outputting board configurations,
//return the total number of distinct solutions.

namespace Solution1
{
	void setQueen(vector<string>&result, int level, int pos, char c)
	{
		int count = 0;
		while (pos != 0)
		{
			pos >>= 1;
			count++;
		}
		result[level][count - 1] = c;
	}

	void recurseQueen(int maskVertical, int maskDiagL, int maskDiagR, int n, int level, vector<string>&result, int& count)
	{
		if (level == n)
		{
			count++;
			return;
		}

		int candidates = (1 << n) - 1;
		candidates = candidates & (~(maskVertical | maskDiagL | maskDiagR));
		while (candidates)
		{
			int candidatePos = candidates & (~candidates + 1);
			candidates -= candidatePos;
			setQueen(result, level, candidatePos, 'Q');
			recurseQueen(maskVertical | candidatePos, (maskDiagL | candidatePos) << 1, (maskDiagR | candidatePos) >> 1, n, level + 1, result, count);
			setQueen(result, level, candidatePos, '.');
		}
	}

	int totalNQueens(int n) 
	{
		int count = 0;
		vector<string> result(n, string(n, '.'));
		recurseQueen(0, 0, 0, n, 0, result, count);
		return count;
	}
	
	void NQueensII()
	{
	
	}
}