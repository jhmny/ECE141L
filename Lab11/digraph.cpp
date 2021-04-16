#include "edge.h"
#include "digraph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;



Digraph::Digraph(string in) {
	ifstream fin;
	fin.open(in.c_str());
	if (fin.fail()) {
		cout << "Could not open input file: " << in << ".\nExiting the program....." << endl;
		exit(1);
	}
	else {
		string str_edge;
		Edge e;
		fin >> num_V;
		fin >> num_E;
		adj_list.resize(num_V);
		while (!fin.eof()) {
			getline(fin, str_edge);
			if (!str_edge.empty()) {
				e.update(str_edge);
				add_edge(e);
			}
		}
	}
}

Digraph::Digraph(int n) {
		num_V = n;
		num_E = 0;
		adj_list.resize(num_V);
}

void Digraph::add_edge(Edge e) {
	adj_list[e.get_first()].push_back(e.get_last());
}
vector<int> Digraph::adj(int v) {
	return adj_list[v];
}
int Digraph::v_count() {
	return num_V;
}
int Digraph::e_count() {
	return num_E;
}