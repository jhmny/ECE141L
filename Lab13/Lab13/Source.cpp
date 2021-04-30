// Lab 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "DagSP.h"
using namespace std;

typedef vector<vector<int>> matrix;

void allPairSP(const matrix& adj_list, matrix& distTo, matrix& pathTo) {
	int m = numeric_limits<int>::max();
	int V = adj_list.size();
	distTo.resize(V);
	pathTo.resize(V);
	for (int i = 0; i < V; i++) {
		distTo[i].resize(V);
		pathTo[i].resize(V);
		for (int j = 0; j < V; j++)
		{
			distTo[i][j] = adj_list[i][j];
			if (i == j)
				pathTo[i][j] = 0;
			else if (distTo[i][j] != m)
				pathTo[i][j] = i;
			else
				pathTo[i][j] = -1;
		}
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < V; k++)
			{
				if (distTo[j][i] != m && distTo[i][k] != m && distTo[j][i] + distTo[i][k] < distTo[j][k])
				{
					distTo[j][k] = distTo[j][i] + distTo[i][k];
					pathTo[j][k] = pathTo[i][k];
				}
			}
		}
	}
}

int main()
{
	int m = numeric_limits<int>::max();
	matrix adj_list{
		{ 0,5,m,m,9,m,m,8 },
		{ m,0,12,15,m,m,m,4 },
		{ m,m,0,3,m,m,11,m },
		{ m,m,m,0,m,m,9,m },
		{ m,m,m,m,0,4,20,5 },
		{ m,m,1,m,m,0,13,m },
		{ m,m,m,m,m,m,0,m },
		{ m,m,7,m,m,6,m,0 } };
	matrix distTo;
	matrix pathTo;
	allPairSP(adj_list, distTo, pathTo);
	int V = adj_list.size();
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			if (distTo[i][j] > 100)
				cout << "M" << " ";
			else
				cout << distTo[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << pathTo[i][j] << " ";
		cout << endl;
	}
}
