#include <iostream>
#include <stack>

#include "Edge.h"
#include "Digraph.h"
#include "DepthFirstOrder.h"

using namespace std;


//User Functions
void print(stack<unsigned> s);
void print(Digraph g);

int main() {
	
	Digraph g(6);
	g.add_edge(new Edge(2, 4));
	g.add_edge(new Edge(1, 2));
	g.add_edge(new Edge(0, 1));
	g.add_edge(new Edge(4, 3));
	g.add_edge(new Edge(3, 5));
	g.add_edge(new Edge(0, 2));
	print(g);
	cout << "reversing" << endl;
	g.reverse();
	print(g);
	cout << "==========================" << endl;
	cout << "Begin Testing Part 3.4" << endl;
	cout << "Creating Bool Diagrah" << endl;
	Digraph g1(7);
	g1.add_edge(new Edge(0, 2));
	g1.add_edge(new Edge(1, 2));
	g1.add_edge(new Edge(2, 3));
	g1.add_edge(new Edge(4, 5));
	g1.add_edge(new Edge(5, 3));
	g1.add_edge(new Edge(6, 5));
	print(g1);
	cout << "==========================" << endl;
	cout << "Calliing Depth First Order" << endl;
	DepthFirstOrder DFO(g1);
	print(DFO.get_topological_sorted_digraph());
	return 0;
}

void print(Digraph g) {
	for (int i = 0; i < g.v_count(); i++)
	{
		vector<Edge*> temp = g.adj(i);
		for (int j = 0; j < temp.size(); j++)
		{
			temp[j]->to_String();
		}
	}
}
void print(stack<unsigned> s){
	cout << s.size() << endl;
	int sizeStack = s.size();
	for (int i = 0; i < sizeStack; i++) {

		if (i == sizeStack-1) {
			cout << "output node: " << s.top() << " ";
			s.pop();
		}
		else {
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}
