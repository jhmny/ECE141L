#pragma once
#include "digraph.h"

using namespace std;
class DagDFS{
private:
    int count;
    bool* marked; // true if path from s
public:
    DagDFS(Digraph G, int s)  // constructor marks vertices reachable from  s
    {
        marked = new bool[G.v_count()];
        for(int i = 0; i<G.v_count(); i++){
            marked[i] = false;
        }
        count = 0;
        dfs(G,s);

    }
    DagDFS(Digraph G, vector<int> source) // find vertices reachable from sources
    {
        marked = new bool[G.v_count()];
        for (int i = 0; i < G.v_count(); i++) {
            marked[i] = false;
        }
        for (int i = 0; i < source.size(); i++)
        {
            if (marked[i] == false) {
                dfs(G, source[i]);
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
        for(int w : G.adj(v)){ //check to see if int conversion is correct 
            if(!marked [w]){
                dfs(G,w);
            }
        }
    }
};


