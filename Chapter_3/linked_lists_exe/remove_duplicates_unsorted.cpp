#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
    struct Node* next;
    int value;
};

void traversal(struct Node* list)
{
	while(list!=NULL)
	{
		printf("%d->", list->value);
		list = list->next;
	}
}

struct Node* push(struct Node** list, int new_point)
{
    struct Node* new_node = new Node();

    new_node->value = new_point;
    new_node->next = (*list);
    (*list) = new_node;   
}

void removeDuplicates_1(struct Node* list)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = list;

	while(ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
		while(ptr2->next != NULL)
		{
			if(ptr1->value == ptr2->next->value)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

//using hash table
void removeDuplicates_2(struct Node* list)
{
	unordered_set<int> s;

	struct Node *curr = list;
	struct Node *prev = NULL;
	while(curr != NULL)
	{
		if(s.find(curr->value) != s.end())
		{
			prev->next = curr->next;
			delete(curr);
		}
		else
		{
			s.insert(curr->value);
			prev = curr;
		}
		curr = prev->next;
	}
}

int main(int argc, char const *argv[])
{
	struct Node* head = NULL; 
	push(&head,20);
	push(&head,40);
	push(&head,60);
	push(&head,80);
	push(&head,80);
	push(&head,80);
	push(&head,60);
	traversal(head);
	removeDuplicates_2(head);
	printf("DUPA\n");
	traversal(head);
	return 0;
}