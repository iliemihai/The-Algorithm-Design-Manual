#include <iostream>

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

void push_after(struct Node* list, int new_point)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*));
	new_node->value = new_point;
	new_node->next = list->next;
	list->next = new_node;
}

//find predecesor
struct Node* predecesor(struct Node* list, int new_point)
{
	if( list == NULL || list->next == NULL)
		return NULL;

	if(list->next->value == new_point)
		return list;
	else
		return predecesor(list->next, new_point);
}


//delete list by value
void delete_list_val(struct Node** list, int new_point)
{
	struct Node* p;
	struct Node* pred;

	p = search(*list, new_point);
	if( p != NULL)
	{
		pred = predecesor(*list, new_point);

		if(pred == NULL)
			*list = p->next;
		else
			pred->next = p->next;

		free(p);
	}
}

//delete list by position
void delete_list_pos(struct Node** list, int new_pos)
{
	struct Node* p = *list;
	struct Node* pred;
    
	if (new_pos == 0)
	{
		*list = p->next;
		free(p);
		return;
	}

	for(int ind = 0; ind<new_pos-1;ind++)
		p = p->next;

    p->next = p->next->next;
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

void reverse(struct Node* n)
{
	struct Node* prev = NULL;
	struct Node* curr = NULL;
	struct Node* next = NULL;

	while(n != NULL) 
	{
		prev->next = n;
		curr->next = n->next;
		next->next = n->next->next;
		curr->next = prev;
		//next->next = curr;
		n = n->next;
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
    delete_list_val(&first, 2);
    traversal(first);
    free_list(&first);
	return 0;
}