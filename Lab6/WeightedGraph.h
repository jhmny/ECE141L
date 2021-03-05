#pragma once
#ifndef WEIGHTED_GRAPH_H
//Code is from assignment 4
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Edge.h"

using namespace std;

class WeightedGraph
{
private:
	vector<Edge> edge_list;
	vector<vector<Edge>> adj_list;	// adjacency list of the graph
	int num_V, num_E;	// number of vertices and edges
public:
	WeightedGraph(int);
	WeightedGraph(string);
	vector<Edge> adj(int v);
	void add_edge(Edge&);
	int v_count();
	int e_count();
	void resize(int num_V);
	void set_V(int);
	void set_E(int);
	friend ostream& operator<< (ostream&, WeightedGraph&);
	friend ifstream& operator>> (ifstream&, WeightedGraph&);
};

#endif // !WEIGHTED_GRAPH_H