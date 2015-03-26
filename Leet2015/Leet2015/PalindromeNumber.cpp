#include "stdafx.h"

//Determine whether an integer is a palindrome.Do this without extra space.
//
//click to show spoilers.
//
//Some hints :
//Could negative integers be palindromes ? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer.However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow.How would you handle such case ?
//
//There is a more generic way of solving this problem.

namespace Solution1
{
	bool isPalindrome(int x) {		
		if (x < 0) { return false; }

		int div = 1;
		while (x / div >= 10)
		{
			div *= 10;
		}

		while (x > 0)
		{
			int first = x / div;
			int last = x % 10;

			if (first != last){ return false; }
			x = x % div / 10;
			div /= 100;
		}
		return true;
	}

	bool isPalindrome(int x, int &y) {
		if (x < 0) { return false; }
		if (x == 0) { return true; }

		if (isPalindrome(x / 10, y) && (x % 10 == y % 10))
		{
			y /= 10;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isPalindrome2(int x) {
		return isPalindrome(x, x);
	}

	void PalindromeNumber()
	{
		// Error: negative number is not palindrome.
		// Error: to calculate the pow, use >= 10 check
		// Error: after getting rid of the first and last digit, remember the pow should be divide by 100, not 10
		/*print(isPalindrome(1));
		print(isPalindrome(101));
		print(isPalindrome(111));
		print(isPalindrome(100));
		int input = INT_MIN;
		print(isPalindrome(input));
*/
		//print(isPalindrome2(110));
		//print(isPalindrome2(101));
		print(isPalindrome2(12341));
		print(isPalindrome2(100));
	}

};