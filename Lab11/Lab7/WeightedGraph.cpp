#include "WeightedGraph.h"
//Code is from assignment 4

#include "WeightedGraph.h"


WeightedGraph::WeightedGraph(int num_V) {
	this->num_V = num_V;
	resize(num_V);
}

WeightedGraph::WeightedGraph(string in) {
	ifstream fin;
	Edge e(-1, -1, 0);

	fin.open(in.c_str());
	if (fin.fail()) {
		cout << "Could not open input file: " << in << ".\nExiting the program....." << endl;
		exit(1);
	}
	else {
		operator>>(fin, *this);
	}
}

void WeightedGraph::add_edge(Edge& e) {
	adj_list[e.get_first()].push_back(e);
	//edge_list.push_back(e);
}

vector<Edge> WeightedGraph::adj(int v) {
	return adj_list[v];
}

int WeightedGraph::v_count() {
	return num_V;
}

int WeightedGraph::e_count() {
	return num_E;
}

void WeightedGraph::resize(int num_V) {
	adj_list.resize(num_V);
}

void WeightedGraph::set_V(int num_V) {
	this->num_V = num_V;
}

void WeightedGraph::set_E(int num_E) {
	this->num_E = num_E;
}

ostream& operator<< (ostream& cout, WeightedGraph& wg) {
	for (int v = 0; v < wg.v_count(); v++) {
		for (Edge e : wg.adj(v)) {
			cout << e << endl;
		}
	}
	return cout;
}

ifstream& operator>> (ifstream& fin, WeightedGraph& wg) {
	int num_V, num_E;
	Edge e(-1, -1, 0);
	fin >> num_V;
	fin >> num_E;
	wg.set_V(num_V);
	wg.set_E(num_E);
	wg.resize(num_V);
	while (fin >> e)
		wg.add_edge(e);
	return fin;
}
