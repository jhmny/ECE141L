#include <string>
#include <stack>

#include "digraph.h"

using namespace std;
class NFA {
private:
    string re; // match transitions,regex
    Digraph G; // epsilon transition digraph
    int M;  // number of states
public:
    NFA() {}
    NFA(string regexp)
    {
        M = regexp.length();
        re = regexp;
        G = buildEpsilonTransitionDigraph();
    }

    void print(Digraph G)
    {
        //for (int i = 0; i < G.v_count(); i++)
        //{
        //    vector<int> temp = G.adj(i);
        //    for (int j = 0; j < temp.size(); j++)
        //    {
        //        cout << temp.at(j) << endl;
        //    }
       //}
        for (int i = 0; i < G.v_count(); i++) {
                for (int w : G.adj(i))
                cout << i << " -> " << w << endl;
        }
       
    }

    void prints()
    {
        print(G);
    }

    Digraph buildEpsilonTransitionDigraph()
    {
        Digraph G(M + 1);
        stack<int> ops;
        for (int i = 0; i < M; i++)
        {
            int lp = i;

            if (re[i] == '(' || re[i] == '|') ops.push(i);

            else if (re[i] == ')') {
                int OR = ops.top();
                ops.pop();
                if (re[OR] == '|') {
                    lp = ops.top();
                    ops.pop();
                    G.add_edge(Edge(lp, OR + 1));
                    G.add_edge(Edge(OR, i));
                }
                else lp = OR;
            }
            if (i < M - 1 && re[i + 1] == '*') {
                G.add_edge(Edge(lp, i + 1));
                G.add_edge(Edge(i + 1, lp));
            }
            if (re[i] == '(' || re[i] == '*' || re[i] == ')')
                G.add_edge(Edge(i, i + 1));
        }
        return G;
    }

    bool recognizes(string txt)
    {
        vector<int> pc;
        DagDFS dfs_(G, 0);

        for (int v = 0; v < G.v_count(); v++) //v get num of vertices
            if (dfs_.Marked(v))
                pc.push_back(v);

        for (int i = 0; i < txt.length(); i++)
        {
            vector<int> states;
            for (int v : pc)
            {
                if (v == M) continue;
                if ((re[v] == txt.at(i)) || re[v] == '.')
                    states.push_back(v + 1);
            }
            pc.clear();
            pc.shrink_to_fit();
            vector<int> pcv(states.begin(), states.end());
            DagDFS ndfs(G, pcv);
            pc = vector<int>();

            for (int v = 0; v < G.v_count(); v++)
                if (ndfs.Marked(v))
                    pc.push_back(v);
        }
        for (int v : pc)
        {
            if (v == M) return true;
        }
        return false;
    }

};