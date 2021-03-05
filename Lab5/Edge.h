#pragma once
#include <string>
#include <iostream>

using namespace std;

class Edge {
private:
	int first, last; //v and w
public:
	Edge() {
		first = -1;
		last = -1;
	}
	Edge(int a, int b) {
		first = a;
		last = b;
	};

	void update(string str_edge);
	void update(int, int);
	int get_first();
	int get_first() const;
	int get_last();
	int get_last() const;
	void to_String();
	bool operator==(const Edge& e) const;

};
