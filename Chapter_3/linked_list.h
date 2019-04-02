#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <cstdio>
#include <cstdlib>

class Node
{
    public:
	Node* next;
	int data;
};

template<typename T>
class LinkedList
{
    public:
        T size;
        T maxCapacity;
	Node* head;

	LinkedList(T maxCapacity);
	~LinkedList();
        void add(T data);
	T print();
};


#endif
