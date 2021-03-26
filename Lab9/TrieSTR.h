#pragma once
#include<stdlib.h>
#include <string>
#include <queue>
#include "NodeR.h"

using namespace std;

template <class T>
class TrieSTR
{
private:
    const int R = 256;
    NodeR<T>* root = new NodeR<T>;

    NodeR<int>* put(NodeR<int>* x, string key, int val, int d) {
        if (x == nullptr) {
            x = new NodeR<T>;
        }
        if (d == key.length()) {
            x->value++;
            return x;
        }
        char c = key.at(d);
        x->next[c] = put(x->next[c], key, val, d + 1);
        return x;
    }

    NodeR<string>* put(NodeR<string>* x, string key, string val, int d) {
        if (x == nullptr) {
            x = new NodeR<T>;
        }
        if (d == key.length()) {
            if (x->value.empty()) {
                x->value = val;
            }
            else{
                x->value = x->value + ", " + val;
            }
            return x;
        }
        char c = key.at(d);
        x->next[c] = put(x->next[c], key, val, d + 1);
        return x;
    }

    NodeR<T>* get(NodeR<T>* x, string key, int d) {
        if (x == nullptr) {
            return nullptr;
        }
        if (d == key.length()) {
            return x;
        }
        char c = key.at(d);
        return get(x->next[c], key, d + 1);
    }
  
     void collect(NodeR<string>* x, string prefix, queue<string>& q) {
        if (x == nullptr) {
            return;
        }
        if (!x->value.empty()) {
            q.emplace(prefix + " " + x->value);
        }
        for (char c = 64; c < 124; c++) { //only alphas range
            collect(x->next[c], prefix + c, q);
        }
    }
    // void collect(NodeR<T>* x, string prefix, queue<string> q) {
    //     if (x == nullptr) {
    //         return;
    //     }
    //     if (x->val != "") {
    //         q.emplace(prefix);
    //     }
    //     for (char c = 0; c < R; c++) {
    //         collect(x->next[c], prefix + c, q);
    //     }
    // }
public:
	void put(string key, T val) {
        root = put(root, key, val, 0);
    }
    T get(string key) {
        NodeR<T>* x = get(root, key, 0);
        if (x == nullptr) {
            return NULL;
        }
        return x->value;
    }
	bool contains(string key) {
        return get(key) != NULL;
    }
    queue<string>* keys() {
        queue<string> *q = new queue<string>;
            collect(root, "",*q);
        return q;
    }
};
