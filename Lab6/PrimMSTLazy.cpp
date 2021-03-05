#include "PrimMSTLazy.h"

using namespace std;
void PrimMSTLazy::visit(WeightedGraph G, int v) {
	marked[v] = true;
	for (Edge e : G.adj(v))
		if (!marked[e.other(v)])
			pq.push(e);
}

PrimMSTLazy::PrimMSTLazy(WeightedGraph G) {
	marked = new bool(G.v_count());
	for(int i = 0; i < G.v_count(); i++) marked[i] = false;

	visit(G, 0);

	while(!pq.empty() && mst.size() < G.v_count() -1)
	{
		Edge e = pq.top();
		pq.pop();
		int v = e.either();
		int w = e.other(v);

		if(marked[v] && marked[w]) continue;
		mst.push_back(e);
		if (!marked[v]) visit(G, v);
		if (!marked[w]) visit(G, w);
	}
}

vector<Edge> PrimMSTLazy::getMST() {
	return mst;
}