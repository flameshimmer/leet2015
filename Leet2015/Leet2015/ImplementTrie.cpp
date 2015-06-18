#include "stdafx.h"

//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a - z.

namespace Solution1
{
	class TrieNode {
	public:
		bool isEnd;
		char val;
		TrieNode* children[26];
		// Initialize your data structure here.
		TrieNode() {
			isEnd = false;
			for (int i = 0; i < 26; i++)
			{
				children[i] = NULL;
			}
		}
		TrieNode(char c) {
			isEnd = false;
			val = c;
			for (int i = 0; i < 26; i++)
			{
				children[i] = NULL;
			}
		}	
	};

	class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string s) {
			TrieNode* cur = root;
			for (char c : s)
			{
				int index = c - 'a';
				if (cur->children[index] == NULL)
				{
					cur->children[index] = new TrieNode(c);
				}
				cur = cur->children[index];
			}
			cur->isEnd = true;
		}

		// Returns if the word is in the trie.
		bool search(string key) {
			TrieNode* cur = root;
			for (char c : key)
			{
				int index = c - 'a';
				if (cur->children[index] == NULL)
				{
					return false;
				}
				cur = cur->children[index];
			}
			return cur->isEnd;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			TrieNode* cur = root;
			for (char c : prefix)
			{
				int index = c - 'a';
				if (cur->children[index] == NULL)
				{
					return false;
				}
				cur = cur->children[index];
			}
			return true;
		}

	private:
		TrieNode* root;
	};


	void ImplementTrie()
	{
		 Trie trie;
		 trie.insert("a");
		 print(trie.search("a"));
		 print(trie.startsWith("a"));
	}
}