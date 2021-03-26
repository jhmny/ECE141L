#pragma once
#include <queue>

#include "SuffixArray.h"

using namespace std;
class SuffixSort
{
private:
	SuffixArray suffixes;
	queue<int> matches;
	void sort();
public:
	void suffixSort(string);
	void search(string key);
	queue<int> getSearchIndicies();
};

