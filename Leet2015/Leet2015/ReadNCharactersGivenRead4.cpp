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
	// Read4 API.
	int read4(char *buf){ return 4; }


	/**
	* @param buf Destination buffer
	* @param n   Maximum number of characters to read
	* @return    The number of characters read
	*/
	char _buf[4];
	int _readCount = 0;
	int read(char *buf, int n) 
	{
		int remain = n;
		while (remain > 0)
		{
			_readCount = read4(_buf);
			for (int i = 0; i < _readCount && remain > 0; i++)
			{
				*(buf++) = _buf[i];
				remain--;
			}

			if (_readCount < 4) { break; }
		}
		return n - remain;
	}
	void ReadNCharactersGivenRead4()
	{
		
	}
}