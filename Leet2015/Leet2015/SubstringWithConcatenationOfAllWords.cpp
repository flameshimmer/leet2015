#include "stdafx.h"

//You are given a string, S, and a list of words, L, that are all of 
//the same length.Find all starting indices of substring(s) in S that
//is a concatenation of each word in L exactly once and without any 
//intervening characters.
//
//For example, given:
//S : "barfoothefoobarman"
//L : ["foo", "bar"]
//
//	You should return the indices : [0, 9].
//	(order does not matter).

namespace Solution1
{

	vector<int> findSubstring(string S, vector<string> &words) {
		vector<int> res;

		if (words.empty() || words.size()*words[0].size() > S.length())
			return res;

		int lens = S.length();             // string length
		int lenw = words.size();     // number of words
		int wordLen = words[0].size();           // word length

		// give 1..lenw id's to words, this maps each word with an unique id
		unordered_map<string, int> dict;
		dict.reserve(lenw);
		vector<int> toBeFound(lenw, 0);          // baseline counts (needed for repeating words)
		for (int i = 0; i < lenw; i++) {
			if (dict.count(words[i]) == 0)
				dict[words[i]] = i;
			toBeFound[dict[words[i]]]++;
		}

		vector<int> curIdArray;
		curIdArray.reserve(lens / wordLen);

		// try start position from 0 to wordLen-1
		for (int startPos = 0; startPos < wordLen; startPos++) {
			curIdArray.clear();
			// from this specific start position, convert every substr of wordLen to their id's (if the word is valid)
			// or -1, if the word is not in the words
			for (int i = startPos; i + wordLen <= lens; i += wordLen) {
				auto di = dict.find(S.substr(i, wordLen));
				if (di != dict.end())
					curIdArray.push_back(di->second);   // replace known word with id
				else
					curIdArray.push_back(-1);           // replace unknown word with -1
			}

			// Fill the sliding window with first lenw elements
			// we keep the count of each word and calculate error as the distance
			// between the current counts vector and the baseline count vector
			vector<int> hasFound(lenw, 0);
			int err = lenw;
			for (int i = 0; i < lenw - 1; i++) {
				int id = curIdArray[i];
				if (id != -1) {
					err -= abs(hasFound[id] - toBeFound[id]);
					err += abs(hasFound[id] + 1 - toBeFound[id]);
					hasFound[id]++;
				}
			}

			// move the window of size lenw maintaining the counts
			for (int i = 0; i + lenw <= curIdArray.size(); i++) {
				// add next element
				int id = curIdArray[i + lenw - 1];
				if (id != -1) {
					err -= abs(hasFound[id] - toBeFound[id]);
					err += abs(hasFound[id] + 1 - toBeFound[id]);
					hasFound[id]++;
				}

				// if counts match
				if (err == 0)
					res.push_back(startPos + i*wordLen);

				// remove first element
				id = curIdArray[i];
				if (id != -1) {
					err -= abs(hasFound[id] - toBeFound[id]);
					err += abs(hasFound[id] - 1 - toBeFound[id]);
					hasFound[id]--;
				}
			}
		}
		return res;
	}

	vector<int> findSubstring2(string s, vector<string>& words)
	{
		vector<int> result;
		int lenw = words.size();
		int lens = s.size();
		if (lenw == 0 || lens == 0)
		{
			return result;
		}

		unordered_map<string, int> toBeFound;
		for (string word : words)
		{
			toBeFound[word]++;
		}

		int wordLen = words[0].size();
		if (wordLen * lenw > lens) { return result; }

		int endIndex = lens - wordLen * lenw;

		for (int i = 0; i <= endIndex; i++)
		{
			int start = i;
			int foundCount = 0;
			unordered_map<string, int> hasFound;
			while (foundCount < lenw)
			{
				string cur = s.substr(start, wordLen);
				if (toBeFound.count(cur) == 0) { break; }
				hasFound[cur]++;
				if (hasFound[cur] > toBeFound[cur]) { break; }
				foundCount++;
				start += wordLen;
			}

			if (foundCount == lenw)
			{
				result.push_back(i);
			}
		}
		return result;
	}

	namespace other
	{
		vector<int> findSubstring(string s, vector<string>& words)
		{
			vector<int>result;
			int lenw = words.size();
			int lens = s.size();
			int wordLen = words[0].length();
			if (lenw == 0 || ((wordLen * lenw) > lens)) { return result; }


			unordered_map<string, int> toBeFound;
			for (string str : words)
			{
				if (toBeFound.count(str) == 0)
				{
					toBeFound[str] = 1;
				}
				else
				{
					toBeFound[str]++;
				}
			}

			unordered_map<string, int> hasFound;
			for (auto it : toBeFound)
			{
				hasFound[it.first] = 0;
			}

			int found = 0;
			for (int start = 0, end = 0; end + wordLen - 1 < lens;)
			{
				string cur = s.substr(end, wordLen);
				if (toBeFound.count(cur) == 0) { end++; continue; }
				if (hasFound[cur] < toBeFound[cur])
				{
					found++;
				}
				hasFound[cur]++;

				if (found == lenw)
				{
					string cur2 = s.substr(start, wordLen);
					while (toBeFound.count(cur2) == 0 || hasFound[cur] > toBeFound[cur])
					{
						if (toBeFound.count(cur2) == 0)
						{
							start++;
						}
						else
						{
							hasFound[cur]--;
							start += wordLen;
						}

						cur2 = s.substr(start, wordLen);
					}

					if (end + wordLen - start == wordLen * lenw)
					{
						result.push_back(start);
					}
				}
				end += wordLen;
			}
			return result;
		}

	}


	void SubstringWithConcatenationOfAllWords()
	{
		vector<string> L4 = { "aa", "aa", "aa" };
		print(findSubstring(string("aaaaaaaa"), L4));

		vector<string> L = { "foo", "bar" };
		print(findSubstring(string("barfoothefoobarman"), L));

		vector<string> L2 = { "fooo", "barr", "wing", "ding", "wing" };
		print(findSubstring(string("lingmindraboofooowingdingbarrwingmonkeypoundcake"), L2));

		vector<string> L3 = { "a" };
		print(findSubstring(string("a"), L3));
	}
}