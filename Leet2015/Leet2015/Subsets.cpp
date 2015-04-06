#include "stdafx.h"

//Given a set of distinct integers, S, return all possible subsets.
//
//Note:
//Elements in a subset must be in non - descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If S = [1, 2, 3], a solution is :
//
//[
//	[3],
//	[1],
//	[2],
//	[1, 2, 3],
//	[1, 3],
//	[2, 3],
//	[1, 2],
//	[]
//]

namespace Solution1
{
	void subsets(vector<int>& s, int start, int maxLevel, vector<int> result, vector<vector<int>>& results)
	{
		if (start == maxLevel)
		{
			results.push_back(result);
			return;
		}

		subsets(s, start + 1, maxLevel, result, results);
		result.push_back(s[start]);
		subsets(s, start + 1, maxLevel, result, results);
		result.pop_back();
	}
	
	vector<vector<int> > subsets(vector<int> &S) 
	{
		int len = S.size();
		vector<vector<int>>results;
		if (len == 0) { return results; }
		
		sort(S.begin(), S.end());
		vector<int> result;
		subsets(S, 0, len, result, results);
		return results;
	}
	
	namespace other
	{
		void subsets(vector<int>& s, int start, int maxLevel, vector<int> result, vector<vector<int>>& results)
		{
			for (int i = start; i < maxLevel; i++)
			{
				result.push_back(s[i]);
				results.push_back(result);				
				subsets(s, i + 1, maxLevel, result, results);
				result.pop_back();
			}
		}

		vector<vector<int> > subsets(vector<int> &S)
		{
			int len = S.size();
			vector<vector<int>>results;
			if (len == 0) { return results; }

			sort(S.begin(), S.end());
			vector<int> result;
			results.push_back(result);
			subsets(S, 0, len, result, results);
			return results;
		}
	}

	namespace other2
	{
		vector<vector<int> > subsets(vector<int> &S)
		{
			int len = S.size();
			vector<vector<int>>results;
			if (len == 0) { return results; }

			sort(S.begin(), S.end());
						
			int limit = pow(2, len);

			for (int j = 0; j < limit; j++)
			{
				int target = j;
				vector<int> result;
				for (int i = 0; i < len; i++)
				{
					if (target & 1 == 1)
					{
						result.push_back(S[i]);
					}
					target >>= 1;
				}
				results.push_back(result);
			}

			return results;
		}
	}



	void Subsets()
	{
		//print(subsets(createVector({ 1, 2, 3 })));		
		//print(other::subsets(createVector({ 1, 2, 3 })));
		print(other2::subsets(createVector({ 1, 2, 3 })));
	}
}