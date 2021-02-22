#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_set>
#include <list>
#include <iterator>

using namespace std;

template <class T>
class HashTable {
private:
	int ht_size;
	list<T>* arr_of_lists;
public:
	HashTable(int size) {
		ht_size = size;
		arr_of_lists = new list<T>[size];
	}
	~HashTable() {};
	list<T> find(T obj) {
		list<T> list;
		for(int i = 0; i < ht_size; i++)
		{
			//for (it = temp.begin(); it != temp.end(); ++it) //NEED TO ITTERATE CORRECTRLTY S
			for (auto const& it : arr_of_lists[i])
			{
				if(obj == *it)
				{
					list.push_back(*it);
				}
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
	}
	void remove(T obj) {
		size_t key = hash<T>()(obj);

	}
	void rehash() {
	
	}
};
