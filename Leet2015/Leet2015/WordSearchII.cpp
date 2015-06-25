#include "stdafx.h"

//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
//cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once in a word.
//
//For example,
//Given words = ["oath", "pea", "eat", "rain"] and board =
//
//[
//	['o', 'a', 'a', 'n'],
//	['e', 't', 'a', 'e'],
//	['i', 'h', 'k', 'r'],
//	['i', 'f', 'l', 'v']
//]
//Return["eat", "oath"].
//Note:
//You may assume that all inputs are consist of lowercase letters a - z.

namespace Solution1
{
	class Dict{
	public:		
		Dict(vector<string>& words)
		{
			root = new node(-1);
			for (string s : words)
			{
				addToDict(s);
			}
		}
		struct node
		{
			char val;
			node* children[26];
			bool isEnd;

			node(int v)
			{
				val = v;
				isEnd = false;
				for (int i = 0; i < 26; i++)
				{
					children[i] = NULL;
				}
			}
		};

		node* root;
		void addToDict(string s)
		{
			node* cur = root;
			for (char c : s)
			{
				int index = c - 'a';
				if (cur->children[index] == NULL)
				{
					cur->children[index] = new node(c);
				}
				cur = cur->children[index];
			}
			cur->isEnd = true;
		}

		bool isInDict(string s)
		{
			node* cur = root;
			for (char c : s)
			{
				if (cur->children[c - 'a'] == NULL) { return false; }
				cur = cur->children[c - 'a'];
			}
			return cur->isEnd;
		}
	};

	bool isValid(vector<vector<char>>& board, int x, int y, int rowCount, int colCount)
	{
		if (x >= 0 && x < rowCount && y >= 0 && y < colCount && board[x][y] != '-')
		{
			return true;
		}
		return false;
	}

	void findWordsImpl(vector<vector<char>>& board, int curx, int cury, Dict* dict, int rowCount, int colCount, string result, vector<string>& results)
	{
		if (dict->isInDict(result))
		{
			results.push_back(result);
		}
		
		result += board[curx][cury];
		char backup = board[curx][cury];
		board[curx][cury] = '-';

		if (isValid(board, curx, cury - 1, rowCount, colCount))
		{
			findWordsImpl(board, curx, cury - 1, dict, rowCount, colCount, result, results);
		}
		if (isValid(board, curx, cury + 1, rowCount, colCount))
		{
			findWordsImpl(board, curx, cury + 1, dict, rowCount, colCount, result, results);
		}
		if (isValid(board, curx-1, cury, rowCount, colCount))
		{
			findWordsImpl(board, curx - 1, cury, dict, rowCount, colCount, result, results);
		}
		if (isValid(board, curx+1, cury, rowCount, colCount))
		{
			findWordsImpl(board, curx + 1, cury, dict, rowCount, colCount, result, results);
		}
		board[curx][cury] = backup;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		vector<string> results;
		int rowCount = board.size();
		if (rowCount == 0) { return results; }
		int colCount = board[0].size();
		if (colCount == 0) { return results; }

		Dict* d = new Dict(words);
		string result;
		findWordsImpl(board, 0, 0, d, rowCount, colCount, result, results);
		return results;
	}

	void WordSearchII()
	{
		string rawInput[4] = {
			"oaan",
			"etae",
			"ihkr",
			"iflv"
		};
		vector<vector<char>> board = createMatrix(rawInput, 4);
		vector<string> dict = { "eat", "oath" };


		print(findWords(board, dict));
	}
}