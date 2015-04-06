#include "stdafx.h"

//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, 
//or - 1 if needle is not part of haystack.

namespace Solution1
{
	bool match(char* hayStack, char* needle)
	{
		if (strlen(hayStack) < strlen(needle)){ return false; }
		while (*needle != '\0')
		{
			if (*needle != *hayStack)
			{
				return false;
			}
			hayStack++;
			needle++;
		}
		return true;
	}

	int strStr(char *haystack, char *needle) 
	{	
		if (*needle == '\0') { return (*haystack == '\0') ? 0 : -1; }
		int i = -1;
		while (*haystack != '\0')
		{
			if (*haystack == *needle && match(haystack, needle))
			{
				return i;
			}
			haystack++;
			i++;
		}
		return i;
	}

	void ImplementStrStr()
	{
	
	}
}