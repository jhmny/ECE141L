#include "DepthFirstOrder.h"
#include "Digraph.h"
#include <stack>

using namespace std;

void DepthFirstOrder::depth_first(Digraph g, int v)
{
	marked[v] = true;
	for (Edge* w : g.adj(v)) {             //iterate through each vertex 
		if (!marked[w->get_last()]) { //using dfs, if the edge had already been used then it's a back edge and the graph has a cycle
			//w->to_String();
			depth_first(g, w->get_last());
		}
	}
	reversePostOrder.push(v);
}

DepthFirstOrder::DepthFirstOrder(Digraph g) {
	marked = new bool[g.v_count()];
	//cout << "\n this is vcount  " << g.v_count() << endl;
	for(int i = 0; i < g.v_count(); i++)
	{
		marked[i] = false;
	}
	for(int i = 0; i < g.v_count(); i++)
	{
		if(marked[i] == false){
			depth_first(g, i);
		}
		
	}
}

stack<unsigned> DepthFirstOrder::get_topological_sorted_digraph()
{
	return reversePostOrder;
}
