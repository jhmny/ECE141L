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
    for(int i = 0; i < G.v_count(); i++){
        marked[i] = false;
    }
    count = 0;
    for(int v = 0; v<G.v_count(); v++)
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
        /*for(Edge* w : G.adj(v)){
            if(!marked [w->get_last()]){
                dfs(G,w->get_last());
            }
        }*/
    }
};

