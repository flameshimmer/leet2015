#include "stdafx.h"

//Design and implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and set.
//
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, 
//it should invalidate the least recently used item before inserting a new item.

namespace Solution1
{
	namespace hasError{
		class LRUCache{
		public:
			struct Node{
				int key;
				int val;
				Node* next;
				Node* prev;
				Node(int k, int v)
				{
					key = k;
					val = v;
					next = NULL;
					prev = NULL;
				}
			};

			Node* root;
			Node* last;
			int m_cap;
			int len;
			unordered_map<int, Node*> m_map;
			LRUCache(int capacity) {
				root = new Node(-1, -1);
				last = root;
				m_cap = capacity;
				len = 0;
			}

			int get(int key) {
				if (m_map.find(key) == m_map.end()) { return -1; }
				else if (last->key != key)
				{
					Node* cur = m_map[key];
					cur->prev->next = cur->next;
					cur->next = NULL;
					last->next = cur;
					cur->prev = last;
					last = cur;
				}
				return last->val;
			}

			void set(int key, int value) {
				if (get(key) == -1)
				{
					Node* newNode = new Node(key, value);
					last->next = newNode;
					newNode->prev = last;
					m_map[key] = newNode;
					last = newNode;
					len++;

					while (len > m_cap)
					{
						Node* old = root->next;
						m_map.erase(old->key);
						root->next = root->next->next;
						if (root->next)
						{
							root->next->prev = root;
						}
						delete old;
						len--;
					}
				}
			}
		};
	}

	class LRUCache{
	public:
		int m_cap;
		unordered_map<int, pair<list<int>::iterator, int>> m_map;
		list<int> m_list;
		LRUCache(int capacity) {
			m_cap = capacity;
		}

		int get(int key) {
			if (m_map.find(key) == m_map.end()) { return -1; }
			moveToFront(key);
			return m_map[key].second;
		}

		void set(int key, int value) {
			if (m_map.find(key) == m_map.end())
			{
				m_list.push_front(key);
				m_map[key] = make_pair(m_list.begin(), value);
				
				if (m_list.size() > m_cap)
				{
					m_map.erase(m_list.back());
					m_list.pop_back();
				}
			}
			else
			{
				m_map[key].second = value;
				moveToFront(key);
			}
		}

		void moveToFront(int key)
		{
			auto it = m_map[key].first;
			m_list.erase(it);
			m_list.push_front(key);
			m_map[key].first = m_list.begin();
		}
	};


	void LRUCacheEntry()
	{
		LRUCache* cache = new LRUCache(1);
		//cache->set(2, 1);
		//print(cache->get(2));
		//cache->set(3, 2);
		//print(cache->get(2));
		//print(cache->get(3));

		//cache->set(2, 1);
		//cache->set(2, 2);
		//print(cache->get(2));
		//cache->set(1, 1);
		//cache->set(4, 1);
		//print(cache->get(2));

		//2,[set(2,1),set(1,1),get(2),set(4,1),get(1),get(2)]

		cache = new LRUCache(10);
		cache->set(7, 28);
		cache->set(7, 1);
		cache->set(8, 15);
		print(cache->get(6));
		cache->set(10, 27);
		cache->set(8, 10);
		print(cache->get(8));
		cache->set(6, 29);
		cache->set(1, 9);
		print(cache->get(6));
		cache->set(10, 7);
		print(cache->get(1));
		print(cache->get(2));
		print(cache->get(13));
		cache->set(8, 30);
		cache->set(1, 5);
		print(cache->get(1));
		cache->set(13, 2);
		print(cache->get(12));
	}
}