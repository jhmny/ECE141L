#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "DirectedEdge.h"
#include "EdgeWeightedDigraph.h"
#include "IndexMinPQ.h"

using namespace std;


class DirectedDFS {
private:
	bool* marked;
	bool* recursive;
public:
	DirectedDFS(EdgeWeightedDigraph G) {
		marked = new bool[G.v()];
		recursive = new bool[G.v()];
		for (int i = 0; i < G.v(); i++) {
			marked[i] = false;
			recursive[i] = false;
		}
	}
	bool visited(int v) {
		return marked[v];
	}
	bool isACycle(EdgeWeightedDigraph G) {
		for (int i = 0; i < G.v(); i++)
		{
			if (dfs(G, i)) return true;
		}
		return false;
	}
private:
	bool dfs(EdgeWeightedDigraph G, int v) {
		marked[v] = true;
		recursive[v] = true;
		for (DirectedEdge* w : G.adj(v)) {             //iterate through each vertex
			if (!marked[w->dest(v)] && dfs(G, w->dest(v)))     //using dfs, if the edge had already been used then it's a back edge and the graph has a cycle
				return true;
			else if (recursive[w->dest(v)])
				return true;
		}
		recursive[v] = false;                 //end with resetting the recursive 
		return false;
	}
};

class DepthFirstOrder
{
private:
	bool* marked;
	stack<unsigned> reversePostOrder;
	void depth_first(EdgeWeightedDigraph g, int v) {
		marked[v] = true;
		for (DirectedEdge* w : g.adj(v)) {             //iterate through each vertex 
			if (!marked[w->to()]) { //using dfs, if the edge had already been used then it's a back edge and the graph has a cycle
				//w->to_String();
				depth_first(g, w->to());
			}
		}
		reversePostOrder.push(v);
	}
public:
	DepthFirstOrder(EdgeWeightedDigraph g) {
		marked = new bool[g.v()];
		//cout << "\n this is vcount  " << g.v_count() << endl;
		for (int i = 0; i < g.v(); i++)
		{
			marked[i] = false;
		}
		for (int i = 0; i < g.v(); i++)
		{
			if (marked[i] == false) {
				depth_first(g, i);
			}

		}
	}
	stack<unsigned> get_topological_sorted_digraph() {
		return reversePostOrder;
	}
};

class DagSP {
private:
	vector<DirectedEdge*> edgeTo;
	vector<double> distTo;
	bool isDag;
	IndexMinPQ<double> pq = IndexMinPQ<double>();
public:
	DagSP(EdgeWeightedDigraph G, int s)
	{
		isDag = false;
		DirectedDFS dfs = DirectedDFS(G);
		isDag = dfs.isACycle(G);
		if (!isDag)
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
