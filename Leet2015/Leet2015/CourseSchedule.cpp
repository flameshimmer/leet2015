#include "stdafx.h"

//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//
//For example :
//
//2, [[1, 0]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0. So it is possible.
//
//2, [[1, 0], [0, 1]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0, 
//and to take course 0 you should also have finished course 1. So it is impossible.
//
//Note:
//The input prerequisites is a graph represented by a list of edges, not adjacency matrices.Read more about how a graph is represented.

namespace Solution1
{
	
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		vector<vector<int>> children(numCourses, vector<int>());
		vector<int> inDegree(numCourses, 0);

		for (pair<int, int> p : prerequisites)
		{
			children[p.second].push_back(p.first);
			inDegree[p.first]++;
		}
		
		stack<int> s;
		for (int i = 0; i < inDegree.size(); i++)
		{
			if (inDegree[i] == 0)
			{
				s.push(i);
			}
		}
		
		int zeroDegreeNodeCount = 0;
		while (!s.empty())
		{
			int cur = s.top();
			s.pop();
			zeroDegreeNodeCount++;

			for (int child : children[cur])
			{
				inDegree[child]--;
				if (inDegree[child] == 0)
				{
					s.push(child);
				}
			}
		}
		return zeroDegreeNodeCount == numCourses;
	}

	namespace dfs{
		bool hasCycle(int cur, vector<vector<int>>& children, vector<bool>& visited, vector<bool>& flaged)
		{
			flaged[cur] = true;
			
			for (int child : children[cur])
			{
				if (visited[child]) { return true; }
				visited[child] = true;
				if (hasCycle(child, children, visited, flaged))
				{
					return true;
				}
				visited[child] = false;
			}
			return false;
		}

		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
		{
			vector<vector<int>> children(numCourses, vector<int>());

			for (pair<int, int> p : prerequisites)
			{
				children[p.second].push_back(p.first);			
			}

			vector<bool>flaged(numCourses, false);
			for (int i = 0; i < numCourses; i++)
			{
				vector<bool>visited(numCourses, false);				
				if (!flaged[i] && hasCycle(i, children, visited, flaged))
				{
					return false;
				}
			}
			return true;
		}
	
	}
	vector<pair<int, int>> createInput(vector<vector<int>> rawInput)
	{
		vector<pair<int, int>> result;
		for (vector<int> input : rawInput)

		{
			int first = input[0];
			int second = input[1];
			result.push_back({ first, second });
		}
		return result;
	}

	void CourseSchedule()
	{
		vector<pair<int, int>>input;
		input = createInput({ { 2, 0 }, { 2, 1 } });
		print(dfs::canFinish(3, input));

		//input = createInput({ { 1, 0 }, { 2, 6 }, { 1, 7 }, { 5, 1 }, { 6, 4 }, { 7, 0 }, { 0, 5 }, { 5, 1 }, { 6, 4 } });
		//print(canFinish(8, input));

		//input = createInput({{0, 1}, {0, 2}, {1, 2}});
		//print(canFinish(3, input));

		/*input = createInput({ { 0, 1 }, { 1, 0 } });
		print(canFinish(2, input));*/
	}
}

