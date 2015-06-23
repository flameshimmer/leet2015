#include "stdafx.h"

//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
//
//For example, given the following matrix :
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.

namespace Solution1
{
	int maximalSquare(vector<vector<char>>& matrix) {
		int rowCount = matrix.size();
		if (rowCount == 0) { return 0; }

		int colCount = matrix[0].size();
		if (colCount == 0) { return 0; }

		// init
		int maxSide = 0;		
		vector<int> M(colCount, 0);
		for (int i = 0; i < colCount; i++)
		{
			M[i] = (matrix[0][i] == '1') ? 1 : 0;
			if (M[i] == 1) { maxSide = 1; }
		}

		for (int i = 1; i < rowCount; i++)
		{
			int lastPrev = 0;
			for (int j = 0; j < colCount; j++)
			{
				if (matrix[i][j] == '1')
				{
					int temp = M[j];
					int prev = j>=1 ? M[j - 1] : 0;
					M[j] = min(min(M[j], prev), lastPrev) + 1;
					lastPrev = temp;
					maxSide = max(maxSide, M[j]);
				}
				else
				{
					lastPrev = 0;
					M[j] = 0;
				}
			}
		}
		int area = maxSide * maxSide;
		return area;
	}

	void MaximalSquare()
	{
		//string rawInput[9] = { "..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.." };
		//string rawInput[1] = { "1" };
		string rawInput[4] =  { 
								"10100",
								"10111",
								"11111",
								"10010" 
								};

		vector<vector<char>> board = createMatrix(rawInput, 4);

		print(maximalSquare(board));
	}
}