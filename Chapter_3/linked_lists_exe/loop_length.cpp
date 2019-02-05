#include <iostream>
#include <unordered_set> 
using namespace std;

struct Node
{
	int value;
	struct Node* next;
};

void push(struct Node** list, int new_point)
{
	struct Node* new_node = new Node();

	new_node->value = new_point;

	new_node->next = (*list);

	(*list) = new_node;
}

int countNodes(struct Node* list)
{
	int count = 1;
	struct Node *temp = list;
	while(temp->next != list)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int loop_length(struct Node* list)
{
	struct Node* slow=list, *fast=list;

	while(slow!=NULL && fast !=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
			return countNodes(slow);
	}
	return 0;
}

int main()
{
	struct Node* head = NULL;
	push(&head,20);
	push(&head,40);
	push(&head,60);
	push(&head,80);
	head->next->next->next->next = head;
	printf("%d \n", loop_length(head)); 
    return 0; 
}