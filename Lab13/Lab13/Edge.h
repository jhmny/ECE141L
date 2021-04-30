#pragma once
//Code is from assignment 4

#ifndef EDGE_H

#define EDGE_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Edge
{
private:
	int first, last;
	double weight;
public:
	Edge() {
		this->first = -1;
		this->last = -1;
		this->weight = 0;
	}
	Edge(const int& first, const int& last, const double& weight) {
		this->first = first;
		this->last = last;
		this->weight = weight;
	}

	Edge(const Edge& e) {
		first = e.get_first();
		last = e.get_last();
		weight = e.get_weight();
	}

	~Edge() {

	}

	int get_first();
	int get_first() const;
	int get_last();
	int get_last() const;
	void set_first(int);
	void set_last(int);
	void set_weight(double);
	double get_weight() const;
	int either() const;
	int other(int) const;
	friend stringstream& operator>>(stringstream&, Edge&);
	friend ifstream& operator>>(ifstream&, Edge&);
	friend ostream& operator<<(ostream&, Edge);
	void operator=(const Edge&);
	bool operator==(const Edge) const;
	bool operator<(const Edge) const;
	bool operator>(const Edge) const;	
};

#endif // !EDGE_H