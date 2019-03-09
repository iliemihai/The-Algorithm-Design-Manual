/*
3-8. Design a data structure to support the following operations:

    insert(x,T) -- Insert item x into the set T.
    delete(k,T) -- Delete the kth smallest element from T.
    member(x,T) -- Return true iff x∈T.

All operations must take O(logn) time on an n-element set.

We will use an augmented binary tree which it will keep the number of
left subtree nodes into it's a var in node structure
*/

#include "binary_tree.h"

BinaryTree<int> *insert_node(BinaryTree<int>* root, BinaryTree<int>* node)
{
	BinaryTree<int>* pTraverse = root;
	BinaryTree<int>* currParrent = root;

	while (pTraverse)
	{
		currParrent = pTraverse;

		if (node->get_data() < pTraverse->get_data())
		{
			//branch to left subtree, increment node count
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
	else if (node->get_data() < currParrent->get_data())
	{
		//insert on left
		currParrent->left = node;
	}
	else
	{
		//inser ton right
		currParrent->right = node;
	}

	return root;
}

//elements are in array
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

/*Algorithm:
start:
    if k == root.leftElements+1
        root is kth node
        goto stop
    else if k > root.leftElements + 1
        k = k-(root.leftElements+1)
        root = root.right
        goto start
    else
        root = root.left
        goto start
stop*/
int k_smalles_element(BinaryTree<int>* root, int k)
{
	int ret = -1;

	if (root)
	{
		BinaryTree<int> *pTraverse = root;

		while (pTraverse)
		{
			if ((pTraverse->left_node_count+1)==k)
			{
                ret = pTraverse->get_data();
                break;
            }
            else if (k>pTraverse->left_node_count)
            {
            	//less nodes on left subtree
            	//goto right
            	k = k - (pTraverse->left_node_count+1);
            	pTraverse = pTraverse->right;
            }
            else
            {
            	//node is in left subtree
            	pTraverse = pTraverse->left;
            }
		}
	}
	return ret;
}

int main(int argc, char**argv)
{
	int el[] = {20, 8, 22, 4, 12, 10, 14 };
	BinaryTree<int>* root = NULL;

	root = binary_search_tree(root, el, 7);

	for (int i=1; i<=7; i++)
	{
		printf("\n kth=%d smalles element is %d\n",i, k_smalles_element(root,i));
	}

	return 0;
}