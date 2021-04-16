

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <memory>
#include <stack>

#include "digraph.h"
#include "regEx.h"

using namespace std;

//class Edge{
//
//private:
//    int first, last; //v and w
//public:
//    Edge() {
//        first = -1;
//        last = -1;
//    }
//    Edge(int a, int b) {
//        first = a;
//        last = b;
//    };
//
//    void update(string str_edge)
//    {
//        auto space = str_edge.find(' ');
//        first = atoi(str_edge.substr(0, space).c_str());
//        last = atoi(str_edge.substr(space + 1).c_str());
//
//    }
//    void update(int f , int l)
//    {
//    first = f;
//    last = l;
//
//    }
//    int get_first()
//    {
//        return first;
//    }
//    int get_first() const
//    {
//        return first;
//    }
//    int get_last()
//    {
//        return last;
//    }
//    int get_last() const
//    {
//        return last;
//    }
//    void to_String()
//    {
//        cout <<first << "->" << last <<endl;
//    }
//    bool operator==(const Edge& e) const
//    {
//          return (first == e.get_first() && last == e.get_last());
//    }
//};

class Digraph{
private:
    vector<vector<Edge*>> adj_list; // adjacency list of the graph
    int num_V, num_E; // number of vertices and edges
public:
    Digraph(){}
    Digraph(int size)
    {
        adj_list.resize(size);
        num_V = size;
        num_E = 0;
    }
    vector<Edge*> Adj(int v)
    {
        return adj_list[v];
    }
    int V()
    {
        return num_V;
    }
    int E()
    {
        return num_E;
    }
    void reverse()
    {
        for(int i = 0; i < num_V; i++)
        {
            vector<Edge*> temp = Adj(i);
            for(int j = 0; j < temp.size(); j++)
            {
                int v = temp[j]->get_first();
                int w = temp[j]->get_last();
                temp[j]->update(w,v);
            }
        }
    }
    void addEdge(Edge* e)
    {
        adj_list[e->get_first()].push_back(e);
        num_E++;
    }



};

class Dag {
private:
	bool* marked;
	bool* recursive;
public:
	Dag(Digraph G) {
		marked = new bool[G.v_count()];
		recursive = new bool[G.v_count()];
		for (int i = 0; i < G.v_count(); i++) {
			marked[i] = false;
			recursive[i] = false;
		}
	}
	bool visited(int v) {
		return marked[v];
	}
	bool isACycle(Digraph G) {
		for (int i = 0; i < G.v_count(); i++)
		{
			if (dfs(G, i)) return true;
		}
		return false;
	}
private:
	bool dfs(Digraph G, int v) {
		marked[v] = true;
		recursive[v] = true;
		for (Edge w : G.adj(v)) {             //iterate through each vertex
			if (!marked[w.other(v)] && dfs(G, w.other(v))   )  //using dfs, if the edge had already been used then it's a back edge and the graph has a cycle
				return true;
			else if (recursive[w.other(v)])
				return true;	
		}
		recursive[v] = false;                 //end with resetting the recursive 
		return false;
	}
};

class DagDFS{
private:
    int count;
    bool* marked; // true if path from s
public:
    DagDFS(Digraph G, int s)  // constructor marks vertices reachable from  s
    {
        marked = new bool[G.V()];
        for(int i = 0; i<G.V(); i++){
            marked[i] = false;
        }
        count = 0;
        dfs(G,s);

    }
    DagDFS(Digraph G, vector<int> source) // find vertices reachable from sources
    {
    marked = new bool[G.V()];
    for(int i = 0; i < G.V(); i++){
        marked[i] = false;
    }
    count = 0;
    for(int v = 0; v<G.V(); v++)
    {
        if(marked[v] == false){
            dfs(G,v);
        }
    }
    }
    ~DagDFS(){
        delete[] marked;
    }
    int Count()
    {
        return count;
    }
    bool Marked(int v)   // is v reachable from sources(s)?
    {
        return marked[v];
    }
    void dfs(Digraph G, int v)
    {
        marked[v] = true;
        count++;
        for(Edge* w : G.Adj(v)){
            if(!marked [w->get_last()]){
                dfs(G,w->get_last());
            }

        }
    }
};



class NFA{
private:
    string re; // match transitions,regex
    Digraph G; // epsilon transition digraph
    int M;  // number of states
public:
    NFA(string regexp):re(regexp)
    {
        M  = regexp.size();
        re = regexp;
        G = buildEpsilonTransitionDigraph();
     }

    void print(Digraph G)
    {
        for(int i = 0; i<G.V(); i++)
    {
        vector<Edge*> temp = G.Adj(i);
        for (int j = 0; j < temp.size(); j++)
        {
            temp[j]->to_String();
        }
    }
    }

    void prints()
    {
        print(G);
    }

    bool recognizes(string txt)
    {
        vector<int> pc;
       DagDFS dfs_(G,0);

        for (int v = 0; v < G.V(); v++) //v get num of vertices
            if (dfs_.Marked(v))
                  pc.push_back(v);
               
        for (int i = 0; i < txt.length(); i++)
           {
            vector<int> states;
            for (int v : pc)
            {
                if (v == M) continue;
                if ((re[v] == txt[i]) || re[v] == '.')
                    states.push_back(v+1);
            }
            pc.clear();
            vector<int> pcv(states.begin(), states.end());
            DagDFS ndfs(G,pcv);
            pc = vector<int>();

            for (int v = 0; v < G.V(); v++)
                if (ndfs.Marked(v))
                     pc.push_back(v);
                }
            for (int v : pc)
            {
                if (v == M) return true;
            }
            return false;
   }
    
    Digraph buildEpsilonTransitionDigraph()
    {
        Digraph G(M+1);
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
                       G.addEdge(new Edge(lp, OR+1));
                       G.addEdge(new Edge(OR, i));
                       }
                   else lp = OR;
              }
                    if (i < M-1 && re[i+1] == '*') {
                        G.addEdge(new Edge(lp, i+1));
                        G.addEdge(new Edge(i+1, lp));
                    }
                    if (re[i] == '(' || re[i] == '*' || re[i] == ')')
                    G.addEdge(new Edge(i, i+1));
                    }
                    return G;
    }
};


int main()
{
    string regex="((A*B|AC)D)";
    NFA G(regex);
    G.prints();
    cout <<"----------------------------------" << endl;
    //string txt = "A";

    string re("((A*B|AC)D)");
    Digraph G = buildEpsilonTransitionDigraph(re);
    for (int i = 0; i < G.v_count(); i++) {
        for (int w : G.adj(i))
            cout << i << " -> " << w << endl;
    }
    return 0;

    // cout << G.recognizes(txt) << endl;
return 0;
}
