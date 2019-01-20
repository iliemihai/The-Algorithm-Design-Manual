#include <iostream>
using namespace std;

struct Node
{
	int value;
	struct Node* next;
};

void swapNodes(struct Node** list, int first, int second)
{
	if(first == second)
		return;

	struct Node *prev_f=NULL, *curr_f=*list;
	while(curr_f && curr_f->value != first)
	{
		prev_f = curr_f;
		curr_f = curr_f->next;
	}

	struct Node *prev_s=NULL, *curr_s=*list;
	while(curr_s && curr_s->value!=second)
	{
		prev_s = curr_s;
		curr_s = curr_s->next;
	}

	if(curr_f == NULL || curr_s == NULL)
		return;
	// if first is not head of list
	if(prev_f != NULL)
		prev_f->next = curr_s;
	else
		*list = curr_s;

	//if y is not head of list
	if(prev_s != NULL)
		prev_s->next = curr_f;
	else
		*list = curr_f;

	struct Node *temp = curr_s->next;
	curr_s->next = curr_f->next;
	curr_f->next = temp;
}

struct Node* push(struct Node** list, int new_point)
{
    struct Node* new_node = new Node();

    new_node->value = new_point;
    new_node->next = (*list);
    (*list) = new_node;   
}

void traversal(struct Node* list)
{
	while(list!=NULL)
	{
		printf("%d->", list->value);
		list = list->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	push(&head, 50);
	push(&head, 60);
	swapNodes(&head, 20,50);
	traversal(head);
}