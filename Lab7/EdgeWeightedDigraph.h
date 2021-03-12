#pragma once
#include <iostream>
#include <vector>
#include "DirectedEdge.h"

using namespace std;

class EdgeWeightedDigraph
{
private:
	int V;
	int E;
	vector<vector<DirectedEdge*>> adj_list;
	vector<DirectedEdge*> edge_list;
public:
	EdgeWeightedDigraph(int V)
	{
		this->V = V;
		E = 0;
		adj_list.resize(V);
	}
	void addEdge(DirectedEdge* e)
	{
		int v = e->from();
		adj_list[v].push_back(e);
		edge_list.push_back(e);
		E++;
	}
	vector<DirectedEdge*> adj(int v)
	{
		return adj_list[v];
	}
	int v()
	{
		return V;
	}
};
