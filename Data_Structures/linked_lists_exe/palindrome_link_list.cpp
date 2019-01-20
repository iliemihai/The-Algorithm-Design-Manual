#include <iostream>
using namespace std;

//traverse given linked list and push every node into stack
//traverse list again, for every visited node pop node from stack and 
// compar eit with the node curent visited
// if all nodes matched, return true, else false


//second method 
//find middle of linked list
//reverse second half of linked list
//compare both halfves
//recnstruct linked list
struct Node {
	struct Node* next;
	int value;
};

void traversal(struct Node* list)
{
	while(list!=NULL)
	{
		printf("%c->", list->value);
		list = list->next;
	}
}

void reverse_list(struct Node** list)
{
    struct Node* prev = NULL;
    struct Node* curr = *list;
    struct Node* next = NULL;

    while(curr!=NULL)
    {
    	next = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr = next;
    }
    *list = prev;
}

bool compLists(struct Node *list1, struct Node *list2)
{
	struct Node* temp1 = list1;
	struct Node* temp2 = list2;

	while(temp1 && temp2)
	{
		if(temp1->value == temp2->value)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return false;
	}

	if(temp1 == NULL && temp2 == NULL)
		return true;

	return false;
}

bool isPalindrome(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    struct Node *second_half, *prev_of_slow_ptr = head;
    struct Node *midnode = NULL;//for odd no of elements

    bool res = true;

    if(head!=NULL && head->next!=NULL)
    {
    	while(fast!=NULL && fast->next!=NULL)
    	{
    		fast = fast->next->next;
    		//for odd no of elements
    		prev_of_slow_ptr = slow;
    		slow = slow->next;
    	}

    	if(fast!=NULL)
    	{
    		midnode=slow;
    		slow=slow->next;
    	}

    	second_half = slow;
    	prev_of_slow_ptr->next = NULL;//null terminates first hald
    	reverse_list(&second_half);
    	res = compLists(head, second_half);

    	reverse_list(&second_half);

    	if(midnode!=NULL)
    	{
    		prev_of_slow_ptr->next = midnode;
    		midnode->next = second_half;
    	}
    	else
    		prev_of_slow_ptr->next = second_half;
    }
    return res;
}

struct Node* search(struct Node* list, int new_point)
{
    if(list==NULL)
    	return NULL;

    while(list!=NULL)
    {
    	if(list->value == new_point)
    		return list;
    	else
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

int main()
{
    struct Node* head = NULL; 
    char str[] = "abacaba"; 
    int i; 
  
    for (i = 0; str[i] != '\0'; i++) 
    { 
       push(&head, str[i]);
       traversal(head);
       isPalindrome(head)? printf(" Is Palindrome\n\n"): 
                           printf(" Not Palindrome\n\n"); 
    } 
  
    return 0; 
}