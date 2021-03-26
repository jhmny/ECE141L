#pragma once
#ifndef STRING_ST_H
#define STRING_ST_H

#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

template<class Value, class NodeType, Value(*nullValue)(), const int R = 256>
class trieSTBook {
private:
	shared_ptr<NodeType> root;
public:
	trieSTBook() {
		root = static_cast<shared_ptr<NodeType>>(new NodeType); 
	}
	void insert(string key, Value val);
	bool contains(string key);
	Value get(string key);
	queue<pair<string, Value>> pairs();
private:
	shared_ptr<NodeType> insert(shared_ptr<NodeType> x, string key, Value val, int depth);
	shared_ptr<NodeType> get(shared_ptr<NodeType> x, string key, int depth);
	void pairs(shared_ptr<NodeType> x, string strKey, shared_ptr<queue<pair<string, value>>> queueOfPairs);
};
#endif // !STRING_ST_H