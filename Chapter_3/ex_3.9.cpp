/*
3-9. A concatenate operation takes two sets S1 and S2, where every key in S1 is smaller than any key in S2, and merges them together. Give an algorithm to concatenate two binary search trees into one binary search tree.
The worst-case running time should be O(h), where h is the maximal height of the two trees. 
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

//when the two sets have distinct elements


int main(int argc, char** argv)
{
    int el1[] = {20, 8, 22, 4, 12, 10, 14 };
    int el2[] = {30, 18, 32, 14, 22, 20, 24 };
    BinaryTree<int>* root1 = NULL;

    root1 = binary_search_tree(root1, el1, 7);
    root2 = binary_search_tree(root2, el2, 7);
}