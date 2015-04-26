#include "stdafx.h"

//Given an array of words and a length L, format the text such that each line 
//has exactly L characters and is fully(left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words 
//as you can in each line.Pad extra spaces ' ' when necessary so that each line 
//has exactly L characters.
//
//Extra spaces between words should be distributed as evenly as possible.If the 
//number of spaces on a line do not divide evenly between words, the empty slots
//on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is
//inserted between words.
//
//For example,
//words: ["This", "is", "an", "example", "of", "text", "justification."]
//   L : 16.
//
//Return the formatted lines as :
//[
//	"This    is    an",
//	"example  of text",
//	"justification.  "
//]
//Note : Each word is guaranteed not to exceed L in length.

namespace Solution1
{
	void flush(vector<string>& words, int maxWidth, int cur, int curWidth, int& start, vector<string>& result, bool skipJustification)
	{
		int wordCount = cur - start; 
		string curLine = words[start];
		if (wordCount == 1 || skipJustification)
		{
			for (int i = start+1; i < cur; i++)
			{
				curLine += " " + words[i];
			}
			curLine += string(maxWidth - curLine.length(), ' ');
			result.push_back(curLine);

			start = cur;
			return;
		}
		int spacePerWord = (maxWidth - curWidth) / (wordCount - 1);
		int extraSpacePerWord = (maxWidth - curWidth) % (wordCount - 1);
		
		string space(1 + spacePerWord, ' ');
		for (int i = start + 1; i < cur; i++)
		{			
			curLine += (extraSpacePerWord > 0) ? (space + " ") : space;
			extraSpacePerWord--;
			curLine += words[i];
		}
		result.push_back(curLine);
		start = cur;
	}
	vector<string> fullJustify(vector<string>& words, int maxWidth) 
	{
		int len = words.size();
		vector<string> result;
		if (len == 0) { return result; }

		int start = 0;
		while (start < len)
		{
			int curWidth = 0;			
			int cur = start;
			while (cur < len)
			{
				int newCurWidth = (curWidth == 0) ? words[cur].length() : curWidth + words[cur].length() + 1;
				if (newCurWidth <= maxWidth)
				{ 
					curWidth = newCurWidth;
					cur++;
				}
				else
				{
					flush(words, maxWidth, cur, curWidth, start, result, cur == len);
					break;
				}
			}
			if (cur == len)
			{
				flush(words, maxWidth, cur, curWidth, start, result, cur == len);
				break;
			}
		}
		return result;
	}

	void TextJustification()
	{
		vector<string> words = { "a", "b", "c", "d", "e" };
		print(fullJustify(words, 1));

		words = { "What", "must", "be", "shall", "be." };
		print(fullJustify(words, 12));
	}
}