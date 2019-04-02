/*3-23. Implement an algorithm to reverse a linked list. Now do it without recursion. 
 * int prev, curr, next
 * while curr != NULL
 *     next = curr->next
 *     curr->next = prev
 *     curr = next
 * head = prev
 * */
#include "linked_list.h"

void reverse(Node* h)
{
    Node* curr = h;
    Node* prev = NULL; 
    Node* next = NULL;

    while (curr != NULL)
    {
	next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
    }
    h = prev;
}

int main()
{
    LinkedList<int>* list = new LinkedList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->print();
    reverse(list->head);
    list->print();
}
