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
	
	void RotateImage()
	{
		vector<vector<int>> matrix;
		matrix.push_back(createVector({ 1, 2, 3, 4 }));
		matrix.push_back(createVector({ 5, 6, 7, 8 }));
		matrix.push_back(createVector({ 9, 10, 11, 12 }));
		matrix.push_back(createVector({ 13, 14, 15, 16 }));


		//vector<vector<int>> matrix;
		//matrix.push_back(createVector({ 1, 2, 3 }));
		//matrix.push_back(createVector({ 4, 5, 6 }));
		//matrix.push_back(createVector({ 7, 8, 9 }));

		rotate(matrix);

		print(matrix);
	}
};