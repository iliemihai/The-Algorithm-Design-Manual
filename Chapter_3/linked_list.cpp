#include "linked_list.h"
template<typename T>
LinkedList<T>::LinkedList()
{
    this->size = 0;
    this->length = 0;
    this->head = NULL;
}

template<typename T>
LinkedList<T>::add()
{
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

template<typename T>
void LinkedList::print()
{
    Node* head = this->head;
    int i=1;
    while(head)
    {
        printf("%d: %d ", i, head->data);
	i++;
    }
    printf("\n");
}

template class LinkedList<int>;
