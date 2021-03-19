#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>


class suffix {
private:
	unsigned int idx;
	int n;
	char* ptr;
public:
	suffix(int indx, char* txt, int l) {
		idx = indx;
		n = l - indx;
		ptr = new char;
	}
	unsigned int getIdx() {
		return idx;
	}
	char* getSuffix() {
		return ptr;
	}
	void setIdx(int indx) {
		idx = indx;
	}
	void setSuffix(char* newPtr) {
		ptr = newPtr;
	}
	friend ostream& operator<<(ostream&, suffix);
};

using namespace std;
class SuffixArray
{
private:
	char* txt;
	unsigned int n; 
	vector<suffix> *suffixList;

public:
	SuffixArray(string text);
	unsigned int getLength();
	suffix operator[](const int i) const;
	bool operator<(const SuffixArray) const;
	bool operator>(const SuffixArray) const;
};
