#include "stdafx.h"

//Design a data structure that supports the following two operations :
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string 
//containing only letters a - z or ..A.means it can represent any one letter.
//
//For example :
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true

namespace Solution1
{
	class WordDictionary {
	public:
		struct Node{
			char val;
			vector<Node*> children;
			bool isEnd;
			Node(char c) : val(c), isEnd(false){}			
		};
		Node* root;

		WordDictionary()
		{
			root = new Node('*');
		}

		// Adds a word into the data structure.
		void addWord(string word) {
			Node* cur = root;
			for (char c : word)
			{
				bool foundNode = false;
				for (Node* child : cur->children)
				{
					if (child->val == c)
					{
						cur = child;
						foundNode = true;
						break;
					}
				}
				if (!foundNode)
				{
					Node* newNode = new Node(c);
					cur->children.push_back(newNode);
					cur = newNode;
				}
			}
			cur->isEnd = true;
		}

		// Returns if the word is in the data structure. A word could
		// contain the dot character '.' to represent any one letter.
		bool search(string word) {
			if (word.length() > 0 && root == NULL) { return false; }
			return searchInternal(word, 0, root);
		}

		bool searchInternal(string& word, int level, Node* parent)
		{
			if (level == word.length())
			{
				return parent->isEnd;
			}

			if (word[level] == '.')
			{
				for (Node* child : parent->children)
				{
					if (searchInternal(word, level + 1, child))
					{
						return true;
					}
				}
			}
			else
			{
				for (Node* child : parent->children)
				{
					if (child->val == word[level])
					{
						return searchInternal(word, level + 1, child);
					}					
				}
			}
			return false;
		}
	};
	void AddAndSearchWordDataStructureDesign()
	{
		WordDictionary wordDictionary;
		wordDictionary.addWord("a");
	}
}