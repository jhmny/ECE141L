#pragma once
#ifndef EDGE_H
#define EDGE_H
#include <string>
using namespace std;

class Edge {
public:
	Edge() {
		first = -1;
		last = -1;
	}
	Edge(int _first, int _last) {
		first = _first;
		last = _last;
	}
	void update(string str_edge);
	void update(int, int);
	int get_first();
	int get_first() const;
	int get_last();
	int get_last() const;
	bool operator==(const Edge& e) const;
private:
	int first, last;
};

#endif // !EDGE_H
