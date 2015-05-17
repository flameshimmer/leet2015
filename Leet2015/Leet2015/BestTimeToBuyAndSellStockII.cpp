#include "stdafx.h"

//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like
//(ie, buy one and sell one share of the stock multiple times).However, you may not engage in multiple
//transactions at the same time(ie, you must sell the stock before you buy again).

namespace Solution1
{
	namespace II
	{
		int maxProfit(vector<int>& prices)
		{
			int len = prices.size();
			if (len == 0) { return 0; }

			int maxPriceAfterToday = prices[len - 1];
			int profit = 0;
			for (int i = len - 1; i >= 0; i--)
			{
				maxPriceAfterToday = max(maxPriceAfterToday, prices[i]);
				int prev = (i >= 1) ? prices[i - 1] : 0;
				if (prev > prices[i] || i == 0)
				{
					int diff = maxPriceAfterToday - prices[i];
					if (diff > 0)
					{
						profit += diff;
						maxPriceAfterToday = prices[i];
					}					
				}
			}
			return profit;
		}
	}


	void BestTimeToBuyAndSellStockII()
	{
		vector<int> input = { 1, 2 };
		print(II::maxProfit(input));
	}
}