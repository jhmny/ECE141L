#pragma once
#include <cstdint>
#ifndef NODE_H
#define NODE_H
using namespace std;
template < class Value, Value(*nullValue)(), const int R = 256>
class Node
{
public:
	Node();
	Value get_value() const;
	void set_value(Value);
	shared_ptr<Node> get_Node(char) const;
	void set_Node(uint8_t, shared_ptr<Node>);
	shared_ptr<Node> operator[] (uint8_t);
	bool is_nextValid(uint8_t);
	void set_nextValid(uint8_t, bool);
protected:
	Value value;
	bool nextValid[R]; // for efficiency, change this to be R-bits variable. Look at boost library
	shared_ptr<Node> next[R];
	Value get_null() const; // override this to return the specific nullVal for your specific Value type
};

 template < class Value, Value(*nullValue)(), const int R>
 shared_ptr<Node<Value, nullValue, R>> Node<Value, nullValue, R>::operator[] (uint8_t ch) {
	 return next[ch];
	
}
 template < class Value, Value(*nullValue)(), const int R>
 Node<Value, nullValue, R>::Node() {
	 value = get_null();
	 for (int i = 0; i < R; i++)
		 nextValid[i] = false;
	
}
 template < class Value, Value(*nullValue)(), const int R>
 bool Node<Value, nullValue, R>::is_nextValid(uint8_t ch) {
	 return nextValid[ch];
	
}
template < class Value, Value(*nullValue)(), const int R>
 void Node<Value, nullValue, R>::set_nextValid(uint8_t ch, bool val) {
	 nextValid[ch] = val;
	
}
template < class Value, Value(*nullValue)(), const int R>
 Value Node<Value, nullValue, R>::get_value() const {
	 return value;
	
}
 template < class Value, Value(*nullValue)(), const int R>
 void Node<Value, nullValue, R>::set_value(Value val) {
	 value = val;
	
}
 template < class Value, Value(*nullValue)(), const int R>
 shared_ptr<Node<Value, nullValue, R>> Node<Value, nullValue, R>::get_Node(char ch) const {
	 return next[ch];
}
 template < class Value, Value(*nullValue)(), const int R>
 void Node<Value, nullValue, R>::set_Node(uint8_t ch, shared_ptr<Node> x) {
	 next[ch] = x;
	
}
 template < class Value, Value(*nullValue)(), const int R>
Value Node<Value, nullValue, R>::get_null() const {
	 return nullValue();
	
}
#endif // !NODE_H