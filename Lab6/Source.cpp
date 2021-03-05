#include <iostream>
#include <fstream>

#include "Edge.h"
#include "WeightedGraph.h"
#include "PrimMSTLazy.h"

using namespace std;

int main() {
	cout << "=========================================" << endl;
	cout << "printing WG" << endl;
	WeightedGraph wg("test1.txt");
	cout << wg;

	cout << "=========================================" << endl;
	cout << "printing WG1" << endl;

	WeightedGraph wg1("test2.txt");
	cout << wg1 << endl;
	PrimMSTLazy pmst(wg1);

	cout << "=========================================" << endl;
	cout << "Calling PrimMST on test 2" << endl;
	double total = 0.0;
	vector<Edge> printVec = pmst.getMST();
	for (int i = 0; i < printVec.size(); i++) {
		cout << printVec.at(i);
		total += printVec[i].get_weight();
	}
	cout << endl;
	cout << "Weight: " << total;
	cout << endl;

	cout << "=========================================" << endl;
	cout << "Begin Part 3" << endl;
	cout << "Creating Graph Input File" << endl;
	WeightedGraph powerWG("power.txt");
	cout << powerWG << endl;
	PrimMSTLazy PowerPrim(powerWG);

	total = 0.0;
	cout << "Printing Solution for Power Problem" << endl;
	vector<Edge> printVec1 = PowerPrim.getMST();
	for (int i = 0; i < printVec1.size(); i++) {
		cout << printVec1.at(i);
		total += printVec1[i].get_weight();
	}
	cout << endl;
	cout << "Weight: " << total;
	cout << endl;
	cout << "=========================================" << endl;
	return 0;
}