#pragma once
#include <cstdint>
#ifndef NodeBook_H
#define NodeBook_H
using namespace std;
template < class Value, Value(*nullValue)(), const int R = 256>
class NodeBook
{
public:
	NodeBook();
	Value get_value() const;
	void set_value(Value);
	shared_ptr<NodeBook> get_NodeBook(char) const;
	void set_NodeBook(uint8_t, shared_ptr<NodeBook>);
	shared_ptr<NodeBook> operator[] (uint8_t);
	bool is_nextValid(uint8_t);
	void set_nextValid(uint8_t, bool);
protected:
	Value value;
	bool nextValid[R]; // for efficiency, change this to be R-bits variable. Look at boost library
	shared_ptr<NodeBook> next[R];
	Value get_null() const; // override this to return the specific nullVal for your specific Value type
};

 template < class Value, Value(*nullValue)(), const int R>
 shared_ptr<NodeBook<Value, nullValue, R>> NodeBook<Value, nullValue, R>::operator[] (uint8_t ch) {
	 return next[ch];
	
}
 template < class Value, Value(*nullValue)(), const int R>
 NodeBook<Value, nullValue, R>::NodeBook() {
	 value = get_null();
	 for (int i = 0; i < R; i++)
		 nextValid[i] = false;
	
}
 template < class Value, Value(*nullValue)(), const int R>
 bool NodeBook<Value, nullValue, R>::is_nextValid(uint8_t ch) {
	 return nextValid[ch];
	
}
template < class Value, Value(*nullValue)(), const int R>
 void NodeBook<Value, nullValue, R>::set_nextValid(uint8_t ch, bool val) {
	 nextValid[ch] = val;
	
}
template < class Value, Value(*nullValue)(), const int R>
 Value NodeBook<Value, nullValue, R>::get_value() const {
	 return value;
	
}
 template < class Value, Value(*nullValue)(), const int R>
 void NodeBook<Value, nullValue, R>::set_value(Value val) {
	 value = val;
	
}
 template < class Value, Value(*nullValue)(), const int R>
 shared_ptr<NodeBook<Value, nullValue, R>> NodeBook<Value, nullValue, R>::get_NodeBook(char ch) const {
	 return next[ch];
}
 template < class Value, Value(*nullValue)(), const int R>
 void NodeBook<Value, nullValue, R>::set_NodeBook(uint8_t ch, shared_ptr<NodeBook> x) {
	 next[ch] = x;
	
}
 template < class Value, Value(*nullValue)(), const int R>
Value NodeBook<Value, nullValue, R>::get_null() const {
	 return nullValue();
	
}
#endif // !NodeBook_H