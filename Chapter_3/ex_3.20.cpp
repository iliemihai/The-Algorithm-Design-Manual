#include <iostream>
using namespace std;
//time complexity O(n)
//space complexity O(n)

struct Node{
    struct Node* next;
    int value;
};

void traversal(struct Node* n)
{
	while(n != NULL)
	{
		printf("%d\n", n->value);
		n = n->next;
	}
}

struct Node* search(struct Node* list, int new_point)
{
	if (list == NULL)
		return NULL;


	if (list->value == new_point)
		return list;
	else
		return search(list->next, new_point);

}

void push(struct Node** list, int new_point)
{
	//alocate node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
	//put in the dfata
	new_node->value = new_point;
	//next of new node as head
	new_node->next = *list;
	//move head to point to new node
	*list = new_node;
}


void free_list(struct Node** list)
{
    struct Node* curr = *list;
    struct Node* next;

    while(curr != NULL)
    {
    	next = curr->next;
    	free(curr);
    	curr = next;
    }

    *list = NULL;
}

int length(struct Node** list)
{
	struct Node* node = *list;
    int len = 0;

	while(node != NULL)
	{
        node = node->next;
        len++;
	}
	return len;
}

void middle(struct Node** first)
{
    int len = length(first);
    int mid = (search(*first, len/2+1))->value;
    cout <<"Mijlocul e "<<mid << endl;
}

void middle2(struct Node* first)
{
	struct Node* ptr1 = first;
	struct Node* ptr2 = first;

	if(first!=NULL)
    {
        while(ptr2 != NULL && ptr2->next != NULL)
        {
    	    ptr1 = ptr1->next;
    	    ptr2 = ptr2->next->next;
        }
        cout <<"Mijlocul e "<<ptr1->value << endl;
    }
}

int main()
{
	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* forth = NULL;

	first = (struct Node*)malloc(sizeof(struct Node*));
	second = (struct Node*)malloc(sizeof(struct Node*));
	third = (struct Node*)malloc(sizeof(struct Node*));
	forth = (struct Node*)malloc(sizeof(struct Node*));

    first->value = 1;
    first->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = forth;

    forth->value = 4;
    forth->next = NULL;

    push(&first->next->next->next->next, 5);
    push(&first->next->next->next->next->next, 6);
    middle(&first);
    middle2(first);
    traversal(first);
    free_list(&first);


	return 0;
}