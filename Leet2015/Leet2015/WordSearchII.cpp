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

	bool isValid(vector<vector<char>>& board, int x, int y, int rowCount, int colCount, node* dict)
	{
		return (x >= 0 && x < rowCount && y >= 0 && y < colCount && board[x][y] != '-');
	}

	void findWordsInternal(vector<vector<char>>& board, int x, int y, node* dict, int rowCount, int colCount, string result, vector<string>& results)
	{
		char c = board[x][y];
		dict = dict->children[c - 'a'];
		if (!dict) { return; }

		if (dict->isEnd)
		{ 
			results.push_back(result+c);
			dict->isEnd = false;
		}
		
		board[x][y] = '-';
		if (isValid(board, x - 1, y, rowCount, colCount, dict))
		{
			findWordsInternal(board, x - 1, y, dict, rowCount, colCount, result+c, results);
		}
		if (isValid(board, x + 1, y, rowCount, colCount, dict))
		{		
			findWordsInternal(board, x + 1, y, dict, rowCount, colCount, result + c, results);
		}
		if (isValid(board, x, y-1, rowCount, colCount, dict))
		{		
			findWordsInternal(board, x, y - 1, dict, rowCount, colCount, result + c, results);
		}
		if (isValid(board, x, y+1, rowCount, colCount, dict))
		{		
			findWordsInternal(board, x, y + 1, dict, rowCount, colCount, result + c, results);
		}
		board[x][y] = c;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		vector<string> results;
		int rowCount = board.size();
		if (rowCount == 0) { return results; }
		int colCount = board[0].size();
		if (colCount == 0) { return results; }

		// create dict
		node* root = new node(-1);
		for (string s : words)
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

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				findWordsInternal(board, i, j, root, rowCount, colCount, "", results);
			}
		}
		return results;

	}


	namespace tooSlow
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

			int isInDict(string s)
			{
				node* cur = root;
				for (char c : s)
				{
					if (cur->children[c - 'a'] == NULL) { return 0; }
					cur = cur->children[c - 'a'];
				}
				return (cur->isEnd) ? 2 : 1;
			}
		};

		bool isValid(vector<vector<char>>& board, int x, int y, int rowCount, int colCount, Dict* dict, string result)
		{
			if (x >= 0 && x < rowCount && y >= 0 && y < colCount && board[x][y] != '-')
			{
				result.push_back(board[x][y]);
				return (dict->isInDict(result)) != 0;
			}
			return false;
		}

		void findWordsImpl(vector<vector<char>>& board, int curx, int cury, Dict* dict, int rowCount, int colCount, string result, unordered_set<string>& results)
		{
			result.push_back(board[curx][cury]);
			char backup = board[curx][cury];
			board[curx][cury] = '-';

			if (dict->isInDict(result) == 2)
			{
				results.insert(result);
				print(board);
			}

			if (isValid(board, curx, cury - 1, rowCount, colCount, dict, result))
			{
				findWordsImpl(board, curx, cury - 1, dict, rowCount, colCount, result, results);
			}
			if (isValid(board, curx, cury + 1, rowCount, colCount, dict, result))
			{
				findWordsImpl(board, curx, cury + 1, dict, rowCount, colCount, result, results);
			}
			if (isValid(board, curx - 1, cury, rowCount, colCount, dict, result))
			{
				findWordsImpl(board, curx - 1, cury, dict, rowCount, colCount, result, results);
			}
			if (isValid(board, curx + 1, cury, rowCount, colCount, dict, result))
			{
				findWordsImpl(board, curx + 1, cury, dict, rowCount, colCount, result, results);
			}
			board[curx][cury] = backup;
			result.pop_back();
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
			unordered_set<string> set;
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					findWordsImpl(board, i, j, d, rowCount, colCount, result, set);
				}
			}

			for (string s : set) { results.push_back(s); }
			return results;
		}

	};

	void WordSearchII()
	{
		//string rawInput[4] = {
		//	"oaan",
		//	"etae",
		//	"ihkr",
		//	"iflv"
		//};
		/*vector<string> dict = { "eat", "oath" };*/
		
		
		string rawInput[4] = {
			"aaaa",
			"aaaa",
			"aaaa",
		};		
		vector<string> dict = { "aaaaaaaaaaaa", "aaaaaaaaaaaaa", "aaaaaaaaaaab" };



		vector<vector<char>> board = createMatrix(rawInput, 3);
		print(findWords(board, dict));

	}
}