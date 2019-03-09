#ifndef __BINARYTREE__
#define __BINARYTREE__

#include <cstdio>
#include <cstdlib>

template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	T get_data() {return data;}
	void set_data(T data) {this->data=data;}
	BinaryTree<T> *left;
	BinaryTree<T> *right;
	int left_node_count;

private:
	T data;
};
#endif