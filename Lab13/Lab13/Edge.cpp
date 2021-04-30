//Code is from assignment 4
#include "Edge.h"

using namespace std;
ifstream& operator>>(ifstream& fin, Edge& e) {
	int end_point1, end_point2;
	double weight;
	if (fin >> end_point1)
	{
		e.set_first(end_point1);
		if (fin >> end_point2) {
			e.set_last(end_point2);
			if (fin >> weight)
				e.set_weight(weight);
			else
			{
				cout << "Error: there is not weight provided for the edge (" << end_point1 << "," << end_point2 << ")" << endl;
				exit(1);
			}
		}
		else
		{
			cout << "Error: there is not another end point for the edge with left vertix value " << end_point1 << endl;
			exit(1);
		}
	}
	return fin;
}

stringstream& operator>>(stringstream& ss, Edge& e) {
	int end_point1, end_point2;
	double weight;
	if (ss >> end_point1)
	{
		e.set_first(end_point1);
		if (ss >> end_point2) {
			e.set_last(end_point2);
			if (ss >> weight)
				e.set_weight(weight);
			else
			{
				cout << "Error: there is not weight provided for the edge (" << end_point1 << "," << end_point2 << ")" << endl;
				exit(1);
			}
		}
		else
		{
			cout << "Error: there is not another end point for the edge with left vertix value " << end_point1 << endl;
			exit(1);
		}
	}
	return ss;
}

ostream& operator<<(ostream& cout, Edge e) {
	cout << e.either() << "->" << e.other(e.either()) << " " << e.get_weight() << endl;
	return cout;
}

void Edge::operator=(const Edge& e) {
	first = e.get_first();
	last = e.get_last();
	weight = e.get_weight();
}

int Edge::either() const {
	return first;
}

int Edge::other(int point) const {
	if (point == first)
		return last;
	else
		return first;
}

int Edge::get_first() {
	return first;
}

int Edge::get_first() const {
	return first;
}

int Edge::get_last() {
	return last;
}

int Edge::get_last() const {
	return last;
}

void Edge::set_first(int first) {
	this->first = first;
}

void Edge::set_last(int last) {
	this->last = last;
}

double Edge::get_weight() const {
	return weight;
}

void Edge::set_weight(double weight) {
	this->weight = weight;
}

bool Edge::operator==(const Edge e) const
{
	return (first == e.get_first() && last == e.get_last());
}

bool Edge::operator<(const Edge e) const
{
	return (weight < e.get_weight());
}

bool Edge::operator>(const Edge e) const
{
	return (weight > e.get_weight());
}
