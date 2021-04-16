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
