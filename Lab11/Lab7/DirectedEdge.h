#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class DirectedEdge
{
private:
	int v;
	int w;
	double weight;
public:
	DirectedEdge(int v, int w, double weight)
	{
		this->v = v;
		this->w = w;
		this->weight = weight;
	}
	int from()
	{
		return v;
	}
	int to()
	{
		return w;
	}
	int dest(int v)
	{
		if (this->v == v)
			return w;
		else
			return v;
	}
	int compareTo(DirectedEdge that)
	{
		if (this->weight < that.weight)  return  -1;
		else  if (this->weight > that.weight)  return  +1;
		else return 0;
	}
	bool operator>(const DirectedEdge that) const {
		if (this->weight > that.weight)
			return true;
		else
			return false;
	}
	bool operator<(const DirectedEdge that) const {
		if (this->weight < that.weight)
			return true;
		else
			return false;
	}
	double cost()
	{
		return weight;
	}
};
