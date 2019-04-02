/*3-21. Write a function to compare whether two binary trees are identical. Identical trees have the same key value at each position and the same structure.
 * SOL:
 * To compare the two BST we need to traverse them simultanisly and compare current elements:
 * 1. If both trees are empty then return true
 * 2. Else if both trees are non empty:
 *     check data of root nodes(t1->data == t2->data)
 *     check let subtree recursively (call method(t1->left_subtree, t2->left_subtree))
 *     check the right subtree recursively (call method(t1->right_subtree, t2->right_subtree))
 *     if the values returned in the above trees are true return true
 * 3. Else return false
 * */
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

//when the two sets have distinct elements
void inorder(BinaryTree<int> *root)
{
    if (root == NULL)
	return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int is_identical(BinaryTree<int> *root1, BinaryTree<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
	return 1;
    else if (root1 != NULL && root2 == NULL)
	return 0;
    else if (root1 == NULL && root2 != NULL)
	return 0;
    else 
    {
	if (root1->data == root2->data && is_identical(root1->left, root2->left)
	    && is_identical(root1->right, root2->right))
	    return 1;
	else
	    return 0;
    }
}

int main(int argc, char** argv)
{
    int el1[] = {20, 8, 22, 4, 12, 10, 14 };
    int el2[] = {20, 8, 22, 4, 12, 10, 14 };
    BinaryTree<int>* root1 = NULL;
    BinaryTree<int>* root2 = NULL;

    root1 = binary_search_tree(root1, el1, 7);
    root2 = binary_search_tree(root2, el2, 7);

    if (is_identical(root1, root2))
	printf("\nTrees are identical\n");
    else
	printf("Trees are not identical\n");
}
