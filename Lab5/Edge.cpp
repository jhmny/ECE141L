#include "Edge.h"

#include <string>
#include <iostream>

using namespace std;

void Edge::update(string str_edge) {
	auto space = str_edge.find(' ');
	first = atoi(str_edge.substr(0, space).c_str());
	last = atoi(str_edge.substr(space + 1).c_str());
}
void Edge::update(int f, int l) {
	first = f;
	last = l;
}
int Edge::get_first() { //from
	return first;
}
int Edge::get_first() const {
	return first;
}
int Edge::get_last() { //to
	return last;
}
int Edge::get_last() const {
	return last;
}
bool Edge::operator==(const Edge& e) const
{
	return (first == e.get_first() && last == e.get_last());
}
void Edge::to_String()
{
	cout << first << "->" << last << endl;
}