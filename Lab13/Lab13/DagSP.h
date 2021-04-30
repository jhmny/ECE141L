#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Edge.h"
#include "WeightedGraph.h"
#include "IndexMinPQ.h"

using namespace std;


class DirectedDFS {
private:
	bool* marked;
	bool* recursive;
public:
	DirectedDFS(WeightedGraph G) {
		marked = new bool[G.v_count()];
		recursive = new bool[G.v_count()];
		for (int i = 0; i < G.v_count(); i++) {
			marked[i] = false;
			recursive[i] = false;
		}
	}
	bool visited(int v) {
		return marked[v];
	}
	bool isACycle(WeightedGraph G) {
		for (int i = 0; i < G.v_count(); i++)
		{
			if (dfs(G, i)) return true;
		}
		return false;
	}
private:
	bool dfs(WeightedGraph G, int v) {
		marked[v] = true;
		recursive[v] = true;
		for (Edge w : G.adj(v)) {             //iterate through each vertex
			if (!marked[w.other(v)] && dfs(G, w.other(v))   )  //using dfs, if the edge had already been used then it's a back edge and the graph has a cycle
				return true;
			else if (recursive[w.other(v)])
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
	void depth_first(WeightedGraph g, int v) {
		marked[v] = true;
		for (Edge w : g.adj(v)) {             //iterate through each vertex 
			if (!marked[w.either()]) { //using dfs, if the edge had already been used then it's a back edge and the graph has a cycle
				//w->to_String();
				depth_first(g, w.either());
			}
		}
		reversePostOrder.push(v);
	}
public:
	DepthFirstOrder(WeightedGraph g) {
		marked = new bool[g.v_count()];
		//cout << "\n this is vcount  " << g.v_count() << endl;
		for (int i = 0; i < g.v_count(); i++)
		{
			marked[i] = false;
		}
		for (int i = 0; i < g.v_count(); i++)
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
	vector<Edge> edgeTo;
	vector<double> distTo;
	bool isDag;
	IndexMinPQ<double> pq = IndexMinPQ<double>();
public:
	DagSP(WeightedGraph G, int s)
	{
		isDag = false;
		DirectedDFS dfs = DirectedDFS(G);    // check for cycle
		isDag = dfs.isACycle(G);
		if (!isDag)
		{
			edgeTo.resize(G.v_count());
			distTo.resize(G.v_count());
			pq.resize(G.v_count());

			for (int v = 0; v < G.v_count(); v++)
			{
				distTo[v] = numeric_limits<double>::infinity();
			}
			distTo[s] = 0.0;
			pq.insert(s, 0.0);
			while (!pq.isEmpty())
			{
				int v = pq.delMin();
				for (Edge e : G.adj(v))
					relax(e);
			}
		}
	}
	void relax(Edge e)
	{
		int v = e.either();
		int w = e.other(v);
		if (distTo[w] > distTo[v] + e.get_weight())
		{
			distTo[w] = distTo[v] + e.get_weight();
			edgeTo[w] = e;
			if (pq.contains(w)) pq.decreaseKey(w, distTo[w]);
			else                pq.insert(w, distTo[w]);
		}
	}
	vector<double> dist()
	{
		return distTo;
	}
	vector <Edge> edge()
	{
		return edgeTo;
	}
};
