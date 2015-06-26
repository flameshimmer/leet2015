#include "stdafx.h"

//The demons had captured the princess(P) and imprisoned her in the bottom - right corner of a dungeon.
//The dungeon consists of M x N rooms laid out in a 2D grid.Our valiant knight(K) was initially positioned 
//in the top - left room and must fight his way through the dungeon to rescue the princess.
//
//The knight has an initial health point represented by a positive integer.If at any point his health 
//point drops to 0 or below, he dies immediately.
//
//Some of the rooms are guarded by demons, so the knight loses health(negative integers) upon entering 
//these rooms; other rooms are either empty(0's) or contain magic orbs that increase the knight's health(positive integers).
//
//In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
//
//Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
//
//For example, given the dungeon below, the initial health of the knight must be at least 7
//if he follows the optimal path RIGHT->RIGHT->DOWN->DOWN.
//
//---------------------
//|-2(K)|  -3  |  3  |
//|     |      |     |
//--------------------
//| -5  |  -10 |  1  |
//|     |      |     |
//--------------------
//|     |      |     |
//| 10  |  30  |-5(P)|
//--------------------
//Notes:
//
//The knight's health has no upper bound.
//Any room can contain threats or power - ups, even the first room the knight enters and the bottom - right room where the princess is imprisoned.

namespace Solution1
{

	int calculateMinimumHP(vector<vector<int>>& dungeon) 
	{
		int rowCount = dungeon.size();
		if (rowCount == 0) { return 0; }
		int colCount = dungeon[0].size();
		if (colCount == 0) { return 0; }

		vector<vector<pair<int, int>>> M(colCount, vector<pair<int, int>>(rowCount));

		int c = dungeon[0][0] < 0 ? dungeon[0][0] : 0;
		int g = dungeon[0][0] < 0 ? 0 : dungeon[0][0];
		M[0][0] = make_pair(c, g);

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				if (i == 0 && j == 0) { continue; }
				int leftCost = (j >= 1) ? M[i][j - 1].first : INT_MIN;
				int leftGain = (j >= 1) ? M[i][j - 1].second : 0;
				int topCost = (i >= 1) ? M[i][j].first : INT_MIN;
				int topGain = (i >= 1) ? M[i][j].second : 0;
				int curCost = dungeon[i][j] >= 0 ? 0 : dungeon[i][j];
				int curGain = dungeon[i][j] >= 0 ? dungeon[i][j] : 0;

				int minCost = max(leftCost, topCost);
				int maxGain = (minCost == leftCost) ? leftGain : topGain;

				M[i][j] = make_pair(minCost + curCost, maxGain + curGain);
			}
		}

		int i = 0;
		int j = 0;
		while (i != rowCount && j != colCount)
		{
			if (M[i][j + 1].first > M[i + 1][j].first && j+1)
		}



		int cost = M[j].first;
		int gain = M[j].second;
		int diff = cost + gain;
		if (diff < 0)
		{
			result = max(cost, 1 - diff);
		}

		return result;
	}

	void DungeonGame()
	{
		vector<vector<int>> dungeon;
		dungeon = { { -200 } };
		print(calculateMinimumHP(dungeon));


		dungeon = { 
			{-2, -3, 3},
			{-5, -10, 1},
			{10, 30, -5}
		};
		print(calculateMinimumHP(dungeon));

		dungeon = { { 0, 5 }, {-2, -3} };
		print(calculateMinimumHP(dungeon));
		
		dungeon = { { -3, 5 } };
		print(calculateMinimumHP(dungeon));

		dungeon = { { 2, 1 }, { 1, -1 } };
		print(calculateMinimumHP(dungeon));

		dungeon = { {100}};
		print(calculateMinimumHP(dungeon));
	}
}