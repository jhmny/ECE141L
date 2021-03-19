#include <iostream>
#include <vector>
#include "Edge.h"
#include "WeightedGraph.h"
#include "IndexMinPQ.h"
#include "DagSP.h"
using namespace std;

int main() {
	WeightedGraph wg("test1.txt");

	cout << "Test DAG" << endl;
	DagSP dagsp(wg,0);
	vector<Edge> edgeTo = dagsp.edge();
	vector<double> distTo = dagsp.dist();
	cout << wg;

	//for (int v = 0; v < distTo.size(); v++)
	//{
	//	cout << v << " ";
	//	if (distTo[v] < 10) cout << " " << distTo[v] << "  ";
	//	else cout << distTo[v] << "  ";
	//	if (v != 0) {
	//		cout << edgeTo[v];
	//		cout << endl;
	//	}
	//	else cout << endl << endl;
	//}


	cout << "Test Jobs" << endl;
	WeightedGraph wgJobs("job5.txt");

	cout << "test Job Dag " << endl;
	DagSP dagspJob(wgJobs,20);
	vector<Edge> edgeToJob = dagspJob.edge();
	vector<double> distToJob = dagspJob.dist();

	//for (int v = 0; v < distToJob.size(); v++)
	//{
	//	cout << v << " ";
	//	if (distToJob[v] < 10) cout << " " << distToJob[v] << "  ";
	//	else cout << distToJob[v] << "  ";
	//	if (v != 0) {
	//		cout << edgeToJob[v];
	//		cout << endl;
	//	}
	//	else cout << endl << endl;
	//}
	return 0;
}