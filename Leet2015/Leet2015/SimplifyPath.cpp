#include "stdafx.h"

//Given an absolute path for a file(Unix - style), simplify it.
//
//For example,
//path = "/home/", = > "/home"
//path = "/a/./b/../../c/", = > "/c"

namespace Solution1
{
	string simplifyPath(string path) 
	{
		int len = path.length();
		string result = "/";
		if (len < 2) { return result; }

		vector<string> s;
		int start = 0;
		int end = 1;
		while (end < len)
		{			
			while (end < len && path[end] != '/')
			{
				end++;
			}
			
			string token = path.substr(start + 1, end - start - 1);
			if (token != "" && token != "." && token != "..")
			{
				s.push_back(token);
			}
			else if (!s.empty() && token == "..")
			{
				s.pop_back();
			}
			start = end;
			end = start + 1;
		}

		for (string str : s)
		{
			result += (result == "/") ? str : ("/" + str);
		}
		return result;
	}

	void SimplifyPath()
	{
		print(simplifyPath(string("/home//foo/")));
		print(simplifyPath(string("/")));
		print(simplifyPath(string("/home/")));
		print(simplifyPath(string("/a/./b/../../c/")));
	}
}