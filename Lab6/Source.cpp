#include <iostream>

#include "Edge.h"
#include "WeightedGraph.h"

using namespace std;

int main() {

	WeightedGraph wg("test1.txt");
	cout << wg;
	return 0;
}