#include "stdafx.h"

//The API : int read4(char *buf) reads 4 characters at a time from a file.
//
//The return value is the actual number of characters read.For example, 
//it returns 3 if there is only 3 characters left in the file.
//
//By using the read4 API, implement the function int read(char *buf, int n) 
//that reads n characters from the file.
//
//Note :
//	 The read function will only be called once for each test case.

namespace Solution1
{
	// Forward declaration of the read4 API.
	int read4(char *buf);


	/**
	* @param buf Destination buffer
	* @param n   Maximum number of characters to read
	* @return    The number of characters read
	*/
	int read(char *buf, int n) 
	{
		if (!buf) { return 0; }

		char* cur = buf;
		int remain = n;
		while (remain > 0 && buf != NULL)
		{
			int count = read4(cur);
			remain -= count;
			if (remain < 0)
			{
				count -= -remain;
				remain = 0;
			}
			cur += count;
			if (count < 4) { break; }
		}
		return n - remain;
	}
	void ReadNCharactersGivenRead4()
	{
		
	}
}