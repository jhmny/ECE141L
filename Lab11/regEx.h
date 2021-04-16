#pragma once
#ifndef REGEX_H
#define REGEX_H
#include "edge.h"
#include "digraph.h"
#include <stack>
#include <string>
using namespace std;

Digraph buildEpsilonTransitionDigraph(string re) {
	int M = re.length();
	Digraph G(M + 1);
	stack<int> ops;
	Edge e;
	for (int i = 0; i < M; i++) {
		int lp = i;
		if (re[i] == '(' || re[i] == '|') 
			ops.push(i);
		else if (re[i] == ')') {
			int pos = ops.top();
			ops.pop();
			if (re[pos] == '|') {
				lp = ops.top();
				ops.pop();
				e.update(lp, pos + 1);
				G.add_edge(e);
				e.update(pos, i);
				G.add_edge(e);
			}
			else lp = pos;
		}
		if (i < M - 1 && re[i + 1] == '*') {
			e.update(lp, i + 1);
			G.add_edge(e);
			e.update(i + 1, lp);
			G.add_edge(e);
		}
		if (re[i] == '(' || re[i] == '*' || re[i] == ')') {
			e.update(i, i + 1);
			G.add_edge(e);
		}
	}
	return G;
}

#endif // !REGEX_H
