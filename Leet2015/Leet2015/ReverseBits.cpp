#include "stdafx.h"

//Reverse bits of a given 32 bits unsigned integer.

//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//
//Follow up :
//If this function is called many times, how would you optimize it ?

namespace Solution1
{
	uint32_t reverseBits(uint32_t n) 
	{
		int start = 0;
		int end = 31;
		int cur = n;
		while (start < end && cur != 0)
		{
			int left = (n & (1 << start)) > 0 ? 1 : 0;
			int right = (n & (1 << end)) > 0 ? 1 : 0;
			if (left != right)
			{
				n ^= (1 << start) | (1 << end);
			}			
			cur &= ~(1 << start) | (1 << end);
			start++;
			end--;
		}
		return n;
	}

	uint32_t reverseBits2(uint32_t n)
	{
		n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
		n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
		n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
		n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
	void ReverseBits()
	{
		// Error: time limit exceeded. Special case like 0 and 0xffffffff can directly return
		print(reverseBits(43261596));

		print(reverseBits(1));

		// Error: mistakenly used >> instead of << to create Mask. Remember mask created from 0x1 will need to move left instead of right.
		// Error: bitwise operator's precedence is really low. Signs like > or < are higher precedence. Make sure to add proper parenthese
		// Error: mask & number's value will indicate whether the bit is 0. But if it is not 0, it is likely also not 1. Made the mistake of 
		//        directly compare mask1 & value and mask2 & value. When both of them are bits 1, the value is very likely not equal. eg: 2 
		print(reverseBits(2));

		print(reverseBits2(43261596));
	}
};