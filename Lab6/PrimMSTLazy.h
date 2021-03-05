#pragma once
#include <queue>
#include "WeightedGraph.h"
#include "Edge.h"

using namespace std;

template <class T>
struct comparison {
	bool operator() (const T& a, const T& b)
	{
		return a > b; //will be minimum
	}
};

class PrimMSTLazy
{
private:
	bool* marked;
	vector<Edge> mst;
	priority_queue<Edge, vector<Edge>, comparison<Edge>> pq;
	void visit(WeightedGraph G, int v);
public:
	PrimMSTLazy(WeightedGraph G);
	vector<Edge> getMST();
};

