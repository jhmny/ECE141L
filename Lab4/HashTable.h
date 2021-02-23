#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_set>
#include <vector>
#include <list>

#include "PhoneBookEntry.h"
using namespace std;

namespace std
{
	template<>
	struct hash<PhoneBookEntry>
	{
		size_t operator()(PhoneBookEntry const& a) const
		{
			size_t v = 0;
			for (char c : a.toString())
			{
				v = 31 * v + c;
			}
			return v;
		}
	};
}

template <class T>
class HashTable {
private:
	int ht_size;
	vector<T>* arr_of_lists;
	int elements;
public:
	HashTable(int size) {
		ht_size = size;
		arr_of_lists = new  vector<T>[size];
		elements = 0;
	}
	~HashTable() {};
	vector<T> find(T obj) {
		size_t key = hash<T>()(obj);
		int M = key % ht_size;
		vector<T> list;
		vector<T> temp = arr_of_lists[M];
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j] == obj)
			{
				list.push_back(temp[j]);
			}
		}
		return list;
	}
	void clear() {
		for (int i = 0; i < ht_size; i++) {
			arr_of_lists[i].clear();
		}
	}
	void insert(T obj) {
		size_t key = hash<T>()(obj);
		int M = key % ht_size;
		arr_of_lists[M].push_back(obj);
		elements++;
		
		rehash();
	}
	void remove(T obj) {
		size_t key = hash<T>()(obj);
		int M = key % ht_size;
		for(int i = 0; i < arr_of_lists[M].size(); i++)
		{
			if (obj == arr_of_lists[M].at(i))
			{
				arr_of_lists[M].erase(arr_of_lists[M].begin() + i);
				elements--;
			}
		}
		rehash();
	}
	void rehash() {
		vector<T> list;
		int tempOldSize = ht_size;
		if (elements / ht_size >= 8)
		{
			ht_size = 2 * ht_size;
		}
		else if (elements / ht_size <= 2)
		{
			ht_size = ht_size / 2;
			if (ht_size < 1)
				ht_size = 1;
		}
		else
		{
			return;
		}

		for (int i = 0; i < tempOldSize; i++)
		{
			for (int j = 0; j < arr_of_lists[i].size(); j++)
			{
				list.push_back(arr_of_lists[i].at(j));
			}
			arr_of_lists[i].clear();
		}

		int oldElementSize = elements;
		elements = 0;
		arr_of_lists = new vector<T>[ht_size];
		for(int i = 0; i < oldElementSize; i++)
		{
			size_t key = hash<T>()(list[i]);
			int M = key % ht_size;
			arr_of_lists[M].push_back(list[i]);
			elements++;
		}
		cout << "Size of M: " << ht_size << endl;
	}
};
