#include "stdafx.h"

//There are N children standing in a line.Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements :
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give ?

namespace Solution1
{
	int candy(vector<int>& ratings) {
		int len = ratings.size();
		if (len == 0) { return 0; }

		vector<int> candies(len, 1);
		for (int i = 1; i < len; i++)
		{
			if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i-1])
			{
				candies[i] = candies[i - 1] + 1;
			}
		}
		int total = candies[len-1];
		for (int i = len-2; i >= 0; i--)
		{
			if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
			{
				candies[i] = candies[i + 1] + 1;
			}
			total += candies[i];
		}
		return total;
	}

	void Candy()
	{
		print(candy(createVector({2, 2})));
		print(candy(createVector({ 4, 2, 3, 4, 1 })));
	}
}