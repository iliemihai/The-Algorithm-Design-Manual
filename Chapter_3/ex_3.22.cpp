/*
 *3-22. Write a program to convert a binary search tree into a linked list.
 printLevelOrder(tree)
     for d in height(tree)
         printGivenLevel(tree, d)

 printGivenLevel(tree)
 if tree is NULL return
 if level is 1
     print(tree->data)
 else if level > 1
     printGivenLevel(tree->left, level-1)
     printGIvenLevel(tree->right, level-1)

 Keep track of previous node . Make current node as right child of previous and left node NULL
 * */

#include "binary_tree.h"
#include <queue>

BinaryTree<int> *insert_node(BinaryTree<int>* root, BinaryTree<int>* node)
{
    BinaryTree<int>* pTraverse = root;
    BinaryTree<int>* currParrent = root;

    while (pTraverse)
    {
	currParrent = pTraverse;

	if (node->data < pTraverse->data)
	{
	    //branch to left subtree
	    pTraverse->left_node_count++;
	    //left subtree
	    pTraverse = pTraverse->left;
	}
	else
	{
	    //right subtree
	    pTraverse = pTraverse->right;
	}
    }

    if (!root)
    {
	root = node;
    }
    else if (node->data < currParrent->data)
    {
	//insert left
	currParrent->left = node;
    }
    else
    {
	//insert right
	currParrent->right = node;
    }

    return root;
}

//elements in array
BinaryTree<int>* binary_search_tree(BinaryTree<int>* root, int keys[], int const size)
{
    BinaryTree<int>* newNode = NULL;

    for (int it=0; it<size; it++)
    {
	newNode = new BinaryTree<int>();

	newNode->set_data(keys[it]);
	newNode->left_node_count = 0;
	newNode->left = NULL;
	newNode->right = NULL;

	root = insert_node(root, newNode);
    }

    return root;
}

void inorder(BinaryTree<int>* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void printGivenLevel(node* root, int level);  
int height(node* node);  

void printGivenLevelOrder(BinaryTree* root)
{
    int h = height(root);
    for (int i=1; i<=h; i++)
	printGiv
}

void printGivenLevel(BinartTree* root, int level)
{
    if (root == NULL)
	return;
    if (level == 1)
	printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
	printGivenLevel(root->right, level-1);
    }
}

int height(BinaryTree* root)
{
    if (BinaryTree == NULL)
	return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);

    if (lheight > rheight)
	return (lheight+1);
    else return (rheight+1);
}

void inorder(BinaryTree* root)
{
    if (root == NULL)
	return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void flat_binary_tree(BinaryTree* root, BinaryTree* last)
{
    if (root == NULL)
	return;

    BinaryTree* left = root->let;
    BinaryTree* right = root->right;

    if (root!=*last)
    {
        (*last)->right = root;
	(*last)->left = NULL;
	*last = root;
    }

    flat_binary_tree(left, last);
    flat_binary_tree(right, last);

    if (left == NULL && right == NULL)
	*last = root;
}

int main()
{
    int el1[] = {20, 8, 22, 4, 12, 10, 14 };
    BinaryTree<int>* root1 = NULL;

    root1 = binary_search_tree(root1, el1, 7);

    printf("Level order traversal of binary tree is ");
    printLevelOrder(root);

    BinaryTree* last = root;
    flat_binary_tree(root, &last);

    printLevelOrder(root);
}
