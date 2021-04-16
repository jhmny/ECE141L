#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <memory>
#include <stack>

#include "digraph.h"
#include "regEx.h"
#include "DagDFS.h"
#include "NFA.h"

using namespace std;

int main()
{
    //string re("((A*B|AC)D)");
    //Digraph G = buildEpsilonTransitionDigraph(re);
    //for (int i = 0; i < G.v_count(); i++) {
    //    for (int w : G.adj(i))
    //        cout << i << " -> " << w << endl;
    //}
    Digraph testD("example.txt");

    DagDFS test1(testD, 0);
    if (test1.Marked(5)) cout << "5 reachable" << endl;
    else cout << "5 unreachable" << endl;
    DagDFS test2(testD, 2);
    if (test1.Marked(3)) cout << "3 reachable" << endl;
    else cout << "3 unreachable" << endl;
    vector<int> nums(2);
    nums[0] = 2; nums[1] = 4;
    DagDFS test3(testD, nums);
    if (test1.Marked(3)) cout << "3 reachable" << endl;
    else cout << "3 unreachable" << endl;


    string regex="(GCG(CGG|AGG)*CTG)";
    NFA testNFA(regex);
    testNFA.prints();
    cout <<"----------------------------------" << endl;
    string txt = "GCGGCGTGTGTGCGAGAGAGTGGGTTTAAAGCTGGCGCGGAGGCGGCTGGCGCGGAGGCTG"; //2 true
    cout << testNFA.recognizes(txt) << endl;
    txt = "GCGGCGTGTGTGCGAGAGAGTGGGTTTAAAGCTGGCTCGGAGGCGGCTGGCGCGGAGGCTG"; //1 true 
    cout << testNFA.recognizes(txt) << endl;

    txt = "cheese";
    cout << testNFA.recognizes(txt) << endl;

    return 0;
return 0;
}
