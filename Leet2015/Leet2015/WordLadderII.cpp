#include "stdafx.h"

//Given two words(start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that :
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given :
//	  start = "hit"
//	  end = "cog"
//	  dict = ["hot", "dot", "dog", "lot", "log"]
//	  Return
//	  [
//		  ["hit", "hot", "dot", "dog", "cog"],
//		  ["hit", "hot", "lot", "log", "cog"]
//	  ]
//Note:
//All words have the same length.
//All words contain only lowercase alphabetic characters.

namespace Solution1
{
	namespace II
	{
		vector<string> getChildren(unordered_set<string>& dict, string target)
		{
			vector<string> result;

			for (int i = 0; i < target.length(); i++)
			{
				string cur = target;
				char c = target[i];
				for (int j = 0; j < 26; j++)
				{
					char n = j + 'a';
					if (n != c)
					{
						cur[i] = n;
						if (dict.find(cur) != dict.end())
						{
							result.push_back(cur);
						}
					}
				}
				cur[i] = c;
			}
			return result;
		}

		void processResults(string beginWord, unordered_map<string, pair<int, vector<string>>>& parentMap, string target, vector<string>& result, vector<vector<string>>& results)
		{
			if (target == "")
			{
				if (result.back() == beginWord)
				{
					vector<string> temp = result;
					reverse(temp.begin(), temp.end());
					results.push_back(temp);
				}
				else
				{
					results.push_back(result);
				}				
				return;
			}

			result.push_back(target);
			for (string parent : parentMap[target].second)
			{
				processResults(beginWord, parentMap, parent, result, results);
			}
			result.pop_back();
		}

		vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordDict)
		{
			vector<vector<string>> results;
			wordDict.insert(beginWord);
			wordDict.insert(endWord);

			unordered_set<string> s1;
			s1.insert(beginWord);
			unordered_set<string> s2;
			s2.insert(endWord);

			unordered_set<string> buffer;
			unordered_map<string, pair<int, vector<string>>> parentMap;
			parentMap[beginWord] = make_pair(INT_MAX, vector<string>(1, ""));
			parentMap[endWord] = make_pair(INT_MAX, vector<string>(1, ""));

			bool met = false;
			int level = 2;
			while (!met && !wordDict.empty() && !s1.empty() && !s2.empty())
			{
				if (s1.size() > s2.size()) { swap(s1, s2); }
				for (string target : s1)
				{
					wordDict.erase(target);
					vector<string> children = getChildren(wordDict, target);
					for (string child : children)
					{
						if (s2.find(child) != s2.end())
						{
							met = true;
							vector<string> temp;
							vector<vector<string>> half2s;							
							processResults(beginWord, parentMap, child, temp, half2s);
							vector<vector<string>> half1s;
							processResults(beginWord, parentMap, target, temp, half1s);

							for (int i = 0; i < half1s.size(); i++)
							{
								for (int j = 0; j < half2s.size(); j++)
								{
									vector<string> half1 = half1s[i];
									vector<string> half2 = half2s[j];
									if (half1[0] == beginWord)
									{
										half1.insert(half1.end(), half2.begin(), half2.end());
										results.push_back(half1);
									}
									else
									{
										half2.insert(half2.end(), half1.begin(), half1.end());
										results.push_back(half2);
									}
								}
							}
						}
						else if (s1.find(child) == s1.end())
						{
							buffer.insert(child);
						}
						if (parentMap.find(child) == parentMap.end() || level <= parentMap[child].first)
						{
							parentMap[child].first = level;
							parentMap[child].second.push_back(target);
						}						
					}
				}
				level++;
				swap(s1, buffer);
				buffer.clear();
			}
			return results;
		}	
}

	void WordLadderII()
	{
		string start;
		string end;
		unordered_set<string> dict;


		start = "magic";
		end = "pearl";
		dict = unordered_set<string>({ "flail", "halon", "lexus", "joint", "pears", "slabs", "lorie", "lapse", "wroth", "yalow", "swear", "cavil", "piety", "yogis", "dhaka", "laxer", "tatum", "provo", "truss", "tends", "deana", "dried", "hutch", "basho", "flyby", "miler", "fries", "floes", "lingo", "wider", "scary", "marks", "perry", "igloo", "melts", "lanny", "satan", "foamy", "perks", "denim", "plugs", "cloak", "cyril", "women", "issue", "rocky", "marry", "trash", "merry", "topic", "hicks", "dicky", "prado", "casio", "lapel", "diane", "serer", "paige", "parry", "elope", "balds", "dated", "copra", "earth", "marty", "slake", "balms", "daryl", "loves", "civet", "sweat", "daley", "touch", "maria", "dacca", "muggy", "chore", "felix", "ogled", "acids", "terse", "cults", "darla", "snubs", "boats", "recta", "cohan", "purse", "joist", "grosz", "sheri", "steam", "manic", "luisa", "gluts", "spits", "boxer", "abner", "cooke", "scowl", "kenya", "hasps", "roger", "edwin", "black", "terns", "folks", "demur", "dingo", "party", "brian", "numbs", "forgo", "gunny", "waled", "bucks", "titan", "ruffs", "pizza", "ravel", "poole", "suits", "stoic", "segre", "white", "lemur", "belts", "scums", "parks", "gusts", "ozark", "umped", "heard", "lorna", "emile", "orbit", "onset", "cruet", "amiss", "fumed", "gelds", "italy", "rakes", "loxed", "kilts", "mania", "tombs", "gaped", "merge", "molar", "smith", "tangs", "misty", "wefts", "yawns", "smile", "scuff", "width", "paris", "coded", "sodom", "shits", "benny", "pudgy", "mayer", "peary", "curve", "tulsa", "ramos", "thick", "dogie", "gourd", "strop", "ahmad", "clove", "tract", "calyx", "maris", "wants", "lipid", "pearl", "maybe", "banjo", "south", "blend", "diana", "lanai", "waged", "shari", "magic", "duchy", "decca", "wried", "maine", "nutty", "turns", "satyr", "holds", "finks", "twits", "peaks", "teems", "peace", "melon", "czars", "robby", "tabby", "shove", "minty", "marta", "dregs", "lacks", "casts", "aruba", "stall", "nurse", "jewry", "knuth" });
		II::findLadders(start, end, dict);

		//start = "hit";
		//end = "cog";
		//dict = unordered_set<string>({ "hot", "dot", "dog", "lot", "log" });
		//print(II::findLadders(start, end, dict));

	}
}