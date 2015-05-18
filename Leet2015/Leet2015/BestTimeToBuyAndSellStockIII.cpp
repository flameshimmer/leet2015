#include "stdafx.h"

//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

namespace Solution1
{
	namespace III
	{
		int maxProfit(vector<int>& prices) 
		{
			int len = prices.size();
			if (len == 0) { return 0; }

			vector<int>first(len, INT_MIN);
			vector<int>second(len, INT_MIN);
			int maxP1 = 0;
			int maxP2 = 0;
			int minV = prices[0];
			int maxV = prices[len - 1];
			for (int i = 0; i < len; i++)
			{
				minV = min(minV, prices[i]);
				maxP1 = max(maxP1, prices[i] - minV);
				first[i] = maxP1;
				
				maxV = max(maxV, prices[len - 1 - i]);
				maxP2 = max(maxP2, maxV - prices[len - 1 - i]);
				second[len - 1 - i] = maxP2;				
			}

			int total = INT_MIN;
			for (int i = 0; i < len; i++)
			{
				total = max(total, first[i] + second[i]);
			}
			return total;
		}
	}

	void BestTimeToBuyAndSellStockIII()
	{
		vector<int>input = {2,1,2,0,1};
		print(III::maxProfit(input));
	}
}