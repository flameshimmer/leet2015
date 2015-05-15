#include "stdafx.h"

//Design and implement a TwoSum class.It should support the following operations : add and find.
//
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which sum is equal to the value.
//
//For example,
//add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false
//

namespace Solution1
{
	class TwoSum {
		unordered_map<int, int> map;
	public:
		void add(int number) {
			map[number]++;
		}

		bool find(int value) {
			for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
				int i = it->first;
				int j = value - i;
				if ((i == j && it->second > 1) || (i != j && map.find(j) != map.end())) {
					return true;
				}
			}
			return false;
		}
	};

	void TwoSumIII()
	{
	}
}