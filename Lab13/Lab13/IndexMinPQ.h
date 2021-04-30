#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T>
class IndexMinPQ {
	int max;
	int n;
	vector<int> node;
	vector<int> index;
	vector<T> keys;

public:
	IndexMinPQ<T>() {
		max = 0;
		n = 0;
	}

	void resize(int v)
	{
		max = v;
		n = 0;
		for (int i = 0; i < max; i++)
		{
			index.push_back(-1);
			node.push_back(-1);
			keys.push_back(-1);
		}
	}

	bool isEmpty() {
		if (n == 0) return true;
		else return false;
	}

	bool contains(int i) {
		return index[i] != -1;
	}

	void insert(int i, T key) {
		n++;
		index[i] = n;
		node[n] = i;
		keys[i] = key;
		bubbleUp(n);
	}

	int delMin() {
		int min = node[1];
		exchange(1, n--);
		index[min] = -1;
		node[n + 1] = -1;
		bubbleDown(1);
		return min;
	}

	void decreaseKey(int i, int key) {
		keys[i] = key;
		bubbleUp(index[i]);
	}
	void exchange(int i, int j) {
		int x = node[i];
		node[i] = node[j];
		node[j] = x;
		index[node[i]] = i;
		index[node[j]] = j;
	}
	// used to resort
	void bubbleUp(int k) {
		while (k > 1 && keys[node[k / 2]] > keys[node[k]]) {
			exchange(k, k / 2);
			k = k / 2;
		}
	}
	void bubbleDown(int k) {
		int j;
		while (2 * k <= n) {
			j = 2 * k;
			if (j < n && keys[node[j]] > keys[node[j + 1]])
				j++;
			exchange(k, j);
			k = j;
		}
	}
};