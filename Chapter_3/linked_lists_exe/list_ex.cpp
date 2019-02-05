#include <iostream>
#include <unordered_set>

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



int count(struct Node* n, int val)
{
	int count = 0;
	while(n != NULL)
	{
		if (n->value == val)
            count++;
		n = n->next;
	}

	return count;
}

bool detect_loop(struct Node* l)
{
	std::unordered_set<Node*> hash;
	while(l != NULL)
	{
		if(hash.find(l) != hash.end())
			return true;

		hash.insert(l);
		l = l->next;
	}
	return false;
}

bool detect_loop_fast(struct Node* l)
{
	struct Node* first=l, *second=l;

	while(first && second && second->next)
	{
		first = first->next;
		second = second->next->next;
		if(first == second)
		{
			printf("Found loop\n");
			return true;
		}
	}
	return false;
}

void reverse_linked_list(struct Node** l)
{
	struct Node* prev = NULL;
	struct Node* curr = *l;
	struct Node* next;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*l = prev;
}

bool isPalindrome(struct Node* l)
{
	struct Node *first=l, *second=l;
	
}


int countNodes(struct Node* l)
{
	int res = 1;
	struct Node *temp = l;
	while(temp->next != l)
	{
		res++;
		temp = temp->next;
	}
	return res;
}

//was almoust correct, but count from intersection to itself again
int detectAndCountLoop(struct Node* l)
{
	struct Node *first=l, *second=l;
    
	while(first && second && second->next)
	{
		first = first->next;
		second = second->next->next;

		if(first == second)
		{
			return countNodes(first);
		}
	}
	return 0
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
    forth->next = first;

    push(&first->next->next->next->next, 5);
    delete_list_val(&first, 2);
    if (detect_loop(first)) 
        printf("Loop found\n");
    else
        printf("No loop found\n");
    detect_loop_fast(first);

    traversal(first);
    printf("Counted %d\n", count(first, 3));
    free_list(&first);
	return 0;
}