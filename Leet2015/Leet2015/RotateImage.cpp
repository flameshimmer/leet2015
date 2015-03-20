#include "stdafx.h"

//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).

namespace Solution1
{
	void rotateOneLayer(vector<vector<int>> & matrix, int start, int n)
	{
		vector<int> backupTop(matrix[start].begin(), matrix[start].end());
		int end = n + start - 1;
		
		// left to top
		for (int i = end; i >= start; i--)
		{
			//cout << "copying " << matrix[end - i + start][start] << " to " << matrix[start][i] << "\n";
			matrix[start][i] = matrix[end - i + start][start];
		}
		// bottom to left
		for (int i = start; i <= end; i++)
		{
			//cout << "copying " << matrix[end][i] << " to " << matrix[i][start] << "\n";
			matrix[i][start] = matrix[end][i];
		}
		// right to bottom
		for (int i = end; i >= start; i--)
		{
			//cout << "copying " << matrix[i][end] << " to " << matrix[end][end - i + start] << "\n";
			matrix[end][end - i + start] = matrix[i][end];
		}
		// top to right
		for (int i = end; i >= start; i--)
		{
			//cout << "copying " << backupTop[i] << " to " << matrix[i][end] << "\n";
			matrix[i][end] = backupTop[i];
		}
	}

	void rotate(vector<vector<int> > &matrix) {
		int n = matrix[0].size();
		int layerCount = n / 2;
		for (int i = 0; i < layerCount; i++)
		{
			rotateOneLayer(matrix, i, n - i * 2);
		}
	}


	void rotateOnePoint(vector<vector<int>>& m, int start, int end, int i)
	{		
		cout << "--------------------------"<<i<<"-----------------------------\n";
		// temp top
		int temp = m[start][start + i];
		//cout << "\n\nbackup value is " << temp;
		//print(m);
		// left to top
		//cout << "\n\ncopying " << m[end - i][start] << " to " << m[start][start + i] << "\n";
		m[start][start + i] = m[end - i][start];
		//print(m);
		// bottom to left
		//cout << "\n\ncopying " << m[end][end - i] << " to " << m[end - i][start] << "\n";
		m[end - i][start] = m[end][end-i];
		//print(m);
		// right to bottom
		//cout << "\n\ncopying " << m[start + i][end] << " to " << m[end][end - i] << "\n";
		m[end][end-i] = m[start+i][end];
		//print(m);
		// temp to right
		//cout << "\n\ncopying " << temp << " to " << m[start + i][end] << "\n";
		m[start + i][end] = temp;
		//print(m);
	}
	void rotate2(vector<vector<int>>& matrix)
	{
		int n = matrix[0].size();
		for (int layer = 0; layer < n / 2; layer++)
		{			
			int len = n - 2 * layer;
			int start = layer;
			int end = len + start - 1;
			for (int i = 0; i < len - 1; i++)
			{
				rotateOnePoint(matrix, start, end, i);
			}
			//print(matrix);
		}
	}
	

	
	void RotateImage()
	{
		/*vector<vector<int>> matrix;*/
		//matrix.push_back(createVector({ 1, 2, 3, 4 }));
		//matrix.push_back(createVector({ 5, 6, 7, 8 }));
		//matrix.push_back(createVector({ 9, 10, 11, 12 }));
		//matrix.push_back(createVector({ 13, 14, 15, 16 }));


		//vector<vector<int>> matrix;
		//matrix.push_back(createVector({ 1, 2, 3 }));
		//matrix.push_back(createVector({ 4, 5, 6 }));
		//matrix.push_back(createVector({ 7, 8, 9 }));

		


		vector<vector<int>> matrix;
		matrix.push_back(createVector({ 2, 29, 20, 26, 16, 28 }));
		matrix.push_back(createVector({ 12, 27, 9, 25, 13, 21 }));
		matrix.push_back(createVector({ 32, 33, 32, 2, 28, 14 }));
		matrix.push_back(createVector({ 13, 14, 32, 27, 22, 26 }));
		matrix.push_back(createVector({ 33, 1, 20, 7, 21, 7 }));
		matrix.push_back(createVector({ 4, 24, 1, 6, 32, 34 }));
		
		print(matrix);
		
		//rotate(matrix);
		rotate2(matrix);

		print(matrix);
	}
};