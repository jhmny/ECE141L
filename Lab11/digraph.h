#pragma once
#ifndef DIGRAGH_H
#define DIGRAGH_H
#include <vector>
#include "edge.h"
using namespace std;


class Hash {
public:
	size_t operator()(const Edge& e) const
	{
		return e.get_first();
	}
};

class Digraph {
public:
	Digraph(string);
	Digraph(int);
	vector<int> adj(int);
	int v_count();
	int e_count();
	void add_edge(Edge);
private:
	vector<vector<int>> adj_list; // adjacency list of the graph
	int num_V, num_E; // number of vertices and edges
};

#endif // !DIGRAGH_H
