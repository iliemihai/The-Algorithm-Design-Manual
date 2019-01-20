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

bool detect_loop(struct Node* list)
{
	unordered_set<Node*> s;
	while(list!=NULL)
	{
		if(s.find(list)!=s.end())
		{
			return true;
		}

		s.insert(list);
		list = list->next;
	}
	return false;
}

int main()
{
	struct Node* head = NULL;
	push(&head,20);
	push(&head,40);
	push(&head,60);
	push(&head,80);

	head->next->next->next->next = head;
  
    if (detect_loop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
  
    return 0; 
}