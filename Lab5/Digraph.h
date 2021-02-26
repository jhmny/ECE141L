#pragma once
#include <vector>
#include <fstream>
#include "Edge.h"

using namespace std;
class Digraph {
private:
	vector<vector<Edge*>> adj_list; // adjacency list of the graph
	int num_V, num_E; // number of vertices and edges
public:
	Digraph(string);
	Digraph(int);
	vector<Edge*> adj(int);
	int v_count();
	int e_count();
	void reverse(); //TODO: REVERSE
	void add_edge(Edge*);
};

