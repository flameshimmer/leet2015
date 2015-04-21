#include "stdafx.h"

//Given an integer n, return all distinct solutions to the n - queens puzzle.
//
//Each solution contains a distinct board configuration of the n - queens' placement,
//where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4 - queens puzzle :
//
//[
//	[".Q..",  // Solution 1
//	"...Q",
//	"Q...",
//	"..Q."],
//
//	["..Q.",  // Solution 2
//	"Q...",
//	"...Q",
//	".Q.."]
//]

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
		result[level][count-1] = c;
	}

	void recurseQueen(int maskVertical, int maskDiagL, int maskDiagR, int n, int level, vector<string>&result, vector<vector<string>>&results)
	{
		if (level == n)
		{
			results.push_back(result);
			return;
		}

		int candidates = (1 << n) - 1;
		candidates = candidates & (~(maskVertical | maskDiagL | maskDiagR));
		while (candidates)
		{
			int candidatePos = candidates & (~candidates + 1);
			candidates -= candidatePos;
			setQueen(result, level, candidatePos, 'Q');
			recurseQueen(maskVertical | candidatePos, (maskDiagL | candidatePos) << 1, (maskDiagR | candidatePos) >> 1, n, level + 1, result, results);
			setQueen(result, level, candidatePos, '.');
		}
	}

	vector<vector<string> > solveNQueens(int n)
	{
		vector<vector<string> > results;
		vector<string> result(n, string(n, '.'));
		recurseQueen(0, 0, 0, n, 0, result, results);
		return results;
	}

	namespace other
	{
		bool isLegal(int i, int level, int n, vector<string>& resultRows)
		{
			for (int k = 0; k < level; k++)
			{
				if (resultRows[k][i] == 'Q'){ return false; }
			}
			for (int j = 1; j <= level; j++)
			{
				string curRow = resultRows[level - j];
				if ((i - j >= 0 && curRow[i - j] == 'Q') || (i + j < n && curRow[i + j] == 'Q'))
				{
					return false;
				}
			}
			return true;
		}

		void recurseQueen(int level, int n, vector<string>& resultRows, vector<vector<string>>& results)
		{
			if (level == n)
			{
				results.push_back(resultRows);
				return;
			}

			for (int i = 0; i < n; i++)
			{
				if (isLegal(i, level, n, resultRows))
				{
					resultRows[level][i] = 'Q';
					recurseQueen(level + 1, n, resultRows, results);
					resultRows[level][i] = '.';
				}
			}
		}

		vector<vector<string> > solveNQueens(int n)
		{
			vector<vector<string> >results;
			vector<string>resultRows(n, string(n, '.'));
			recurseQueen(0, n, resultRows, results);
			return results;
		}
	}

	void NQueens()
	{
		vector<vector<string> >results = solveNQueens(1);
		for (vector<string> r : results)
		{
			printStringMatrix(r);
		}	
	}

}