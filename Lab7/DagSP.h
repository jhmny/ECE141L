#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "DirectedEdge.h"
#include "Digraph.h"
#include "IndexMinPQ.h"

using namespace std;

class DijkstraSP {
private:
	vector<DirectedEdge*> edgeTo;
	vector<double> distTo;
	IndexMinPQ<double> pq = IndexMinPQ<double>();
public:
	DijkstraSP(EdgeWeightedDigraph G, int s)
	{
		edgeTo.resize(G.v());
		distTo.resize(G.v());
		pq.resize(G.v());

		for (int v = 0; v < G.v(); v++)
		{
			distTo[v] = numeric_limits<double>::infinity();
		}
		distTo[s] = 0.0;
		pq.insert(s, 0.0);
		while (!pq.isEmpty())
		{
			int v = pq.delMin();
			for (DirectedEdge* e : G.adj(v))
				relax(e);
		}
	}
	void relax(DirectedEdge* e)
	{
		int v = e->from();
		int w = e->dest(v);
		if (distTo[w] > distTo[v] + e->cost())
		{
			distTo[w] = distTo[v] + e->cost();
			edgeTo[w] = e;
			if (pq.contains(w)) pq.decreaseKey(w, distTo[w]);
			else                pq.insert(w, distTo[w]);
		}
	}
	vector<double> dist()
	{
		return distTo;
	}
	vector <DirectedEdge*> edge()
	{
		return edgeTo;
	}
};