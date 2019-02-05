#include <iostream>
using namespace std;

struct Node{
    struct Node* next;
    int value;
};

void push(struct Node** list, int new_point)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));
    new_node->value = new_point;
    new_node->next = *list;
    *list = new_node;
}

void free_list(struct Node** list)
{
	struct Node* curr = *list;
	struct Node* next;

	while(curr!=NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*list = NULL;
}

void traversal(struct Node* n)
{
	while(n != NULL)
	{
		printf("%d\n", n->value);
		n = n->next;
	}
}

void reverse_list(struct Node** list)
{
	struct Node* prev =  NULL;
	struct Node* curr = *list;
	struct Node* next = NULL;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*list = prev;
}

int main()
{
	struct Node* first = NULL;
	first = (struct Node*)malloc(sizeof(struct Node*));
	push(&first->next, 3);
	push(&first->next->next, 5);
	push(&first->next->next->next, 6);
	first->next->next->next->next = NULL;
	printf("Before reverse...\n");
	traversal(first);
	reverse_list(&first);
	printf("After reverse...\n");
	traversal(first);
}
