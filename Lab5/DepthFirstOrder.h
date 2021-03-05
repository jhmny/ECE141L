#pragma once
#include <stack>
#include "Edge.h"
#include "Digraph.h"
class DepthFirstOrder
{
private:
	bool *marked;
	stack<unsigned> reversePostOrder;
	void depth_first(Digraph g, int v);
public:
	DepthFirstOrder(Digraph g);
	stack<unsigned> get_topological_sorted_digraph();
};