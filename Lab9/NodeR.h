#pragma once


template <class T>
class NodeR {
public:
	T value{}; //null
	const int R = 256;
	NodeR* next[256];
	NodeR<T>() {
		for (int i = 0; i < 256; i++) {
			next[i] = nullptr;
		}
	}
};