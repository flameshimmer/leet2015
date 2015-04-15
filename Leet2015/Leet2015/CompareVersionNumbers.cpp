#include "stdafx.h"

//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non - empty and contain only digits and the.character.
//The.character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", 
//it is the fifth second - level revision of the second first - level revision.
//
//Here is an example of version numbers ordering :
//
//0.1 < 1.1 < 1.2 < 13.37

namespace Solution1
{
	int compareVersion(string version1, string version2) 
	{
		int len1 = version1.size();
		int len2 = version2.size();
		int cur1 = 0;
		int cur2 = 0;
		while (cur1 < len1 || cur2 < len2)
		{
			int val1 = 0;
			int val2 = 0;
			while (cur1 < len1 && version1[cur1] != '.')
			{
				val1 = val1 * 10 + version1[cur1] - '0';
				cur1++;
			}
			while (cur2 < len2 && version2[cur2] != '.')
			{
				val2 = val2 * 10 + version2[cur2] - '0';
				cur2++;
			}
			if (val1 == val2) { cur1++; cur2++; continue; }
			else if (val1 > val2) { return 1; }
			else{ return -1; }
		}
		return 0;
	}

	void CompareVersionNumbers()
	{
		print(compareVersion(string("1"), string("0")));
		//Error: did not anticipate the input that has different number of dots or have no dots. Remember to clarify about this.
		print(compareVersion(string("0.1"), string("0.0.1")));
	}
}