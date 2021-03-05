#include <vector>
#include <fstream>
#include "Digraph.h"
#include "Edge.h"

using namespace std;
Digraph::Digraph(string in) {
	ifstream fin;
	fin.open(in.c_str());
	if (fin.fail()) {
		cout << "Could not open input file: " << in << ".\nExiting the program....." << endl;
		exit(1);
	}
	//else {
	//	string str_edge;
	//	Edge* e;
	//	fin >> num_V;
	//	fin >> num_E;
	//	adj_list.resize(num_V);
	//	while (!fin.eof()) {
	//		int v;x
	//		int w;
	//		fin >> v;
	//		fin >> w;
	//		if (!str_edge.empty()) {
	//			e->update(v,w);
	//			add_edge(e);
	//		}
	//	}
	//}
}

Digraph::Digraph(int size) {
	adj_list.resize(size);
	num_V = size;
	num_E = 0;
}

void Digraph::add_edge(Edge* e) {
	adj_list[e->get_first()].push_back(e);
	num_E++;
}
vector<Edge*> Digraph::adj(int v) {
	return adj_list[v];
}
int Digraph::v_count() {
	return num_V;
}
int Digraph::e_count() {
	return num_E;
}

void Digraph::reverse() {
	for(int i = 0; i < num_V; i++)
	{
		vector<Edge*> temp = adj(i);
		for(int j = 0; j < temp.size(); j++)
		{
			int v = temp[j]->get_first();
			int w = temp[j]->get_last();
			temp[j]->update(w,v);
		}
	}
}