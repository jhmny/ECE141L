#pragma once
#include<stdlib.h>
#include <string>
#include <queue>
#include <fstream>
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

    NodeR<T>* put(NodeR<T>* x, string key, string val, int d) {
        if (x == nullptr) {
            x = new NodeR<T>;
        }
        if (d == key.length()) {
                x->value = val;
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
  
     void collect(NodeR<T>* x, string prefix, queue<string>& q) {
        if (x == nullptr) {
            return;
        }
        if (!x->value.empty()) {
            q.emplace(prefix);
        }
        for (char c = 40; c < 124; c++) { //only alphas range
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
    //void read(string str) {
    //    string word = "";
    //    for (auto x : str) {
    //        if (x == ' ') {
    //            //cout << word << endl;
    //            put(word, 0);
    //            word = "";
    //        }
    //        else if (x == ',' || x == '"' || x == '.') { //Removes Notation
    //            continue;
    //        }
    //        else {
    //            word = word + x;
    //        }
    //    }
    //}
    void read(string inputFile) {
        fstream newfile;
        newfile.open(inputFile);
        if (newfile.is_open()) {
            string str2;
            int count = 0;
            while (getline(newfile, str2)) {
                string word2 = "";
                for (auto x : str2) {
                    if (x == ' ') {
                        //cout << word2 << " " << to_string(count) << endl;
                        count++;
                        string testString = to_string(count);
                        put(word2, to_string(count));
                        word2 = "";
                    }
                    else if (x == ',' || x == '"' || x == '.') { //Removes Commas
                        continue;
                    }
                    else {
                        word2 = word2 + x;
                    }
                }
                //cout << word2 <<" "<< to_string(count) << endl;
                put(word2, to_string(count));
            }
            newfile.close();
        }
    }
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

   string LongestPrefixOf(NodeR<T>* x, string s, int d, int& n)
	{
		if (x == nullptr) return;
		if (x->value != 0)
		{
			n = d;
		}
		if (d != s.length())
		{
			int c = (unsigned char)s.at(d);
			LongestPrefixOf(x->next[c], s, d + 1, n);
		}
        return;
	}

	bool contains(string key) {
        return get(key) != NULL;
    }
    queue<string>* keys() { //for grabbing all elements
        queue<string> *q = new queue<string>;
            collect(root, "",*q);
        return q;
    }
    queue<string>* keys(string prefix) { //for prefix matching aka matches
        queue<string>* q = new queue<string>;
        collect(root, prefix, *q);
        return q;
    }

    void thesaurusRead(string inputFile) {
        fstream newfile;
        newfile.open(inputFile);
        if (newfile.is_open()) {
            string str2;
            string def;
            while (getline(newfile, str2)) {
                string word2 = "";
                for (auto x : str2) {
                    if (x == ':') {
                        def = str2.substr(word2.length() + 2, str2.length() - 1);
                        put(def, word2);
                        word2 = "";
                        break;
                    }
                    else if (x == ',' || x == '"' || x == '.') { //Removes Commas
                        continue;
                    }
                    else {
                        word2 = word2 + x;
                    }
                }
            }
            newfile.close();
        }
    }

    void thesaurusCall() {
        cout << "Enter a word" << endl;
        string userWord;
        cin >> userWord;
        cout << "Finding Definition for " << userWord << endl;

        queue<string>* qs = new queue<string>;
        qs = keys(userWord);

        string tempStr2;
        while (!qs->empty()) {
            tempStr2 = qs->front();
            cout << tempStr2 << endl;
            qs->pop();
        }
    }
};
