#include "stdafx.h"

//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock),
//design an algorithm to find the maximum profit.

namespace Solution1
{

	int maxProfit(vector<int>& prices) 
	{
		int len = prices.size();
		if (len == 0) { return 0; }

		int maxPriceAfterToday = prices[len - 1];
		int maxProfit = 0;

		for (int i = len - 1; i >= 0; i--)
		{
			maxPriceAfterToday = max(maxPriceAfterToday, prices[i]);
			maxProfit = max(maxProfit, maxPriceAfterToday - prices[i]);
		}
		return maxProfit;
	}

	void BestTimeToBuyAndSellStock()
	{
	}
}