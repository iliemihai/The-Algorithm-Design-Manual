/*
3-14. Extend the data structure of the previous problem to support insertions and deletions. Each element now has both a key and a value. An element is accessed by its key. The addition operation is applied to the values, but the elements are accessed by its key. The Partial-sum operation is different.

Add(k,y) -- Add the value y to the item with key k.
Insert(k,y) -- Insert a new item with key k and value y.
Delete(k) -- Delete the item with key k.
Partial-sum(k) --
SOL:
Create a balanced binary tree, and in each node store the sub tree sum for the left subtree:

    add(k,v): as key k is searched on the left,the key k value's v is added to each node's subtree sum.
    insert(k, v): TO guarantee O(log N) we have to use a balanced binary tree, such as AVL. At balancing step we have to take care of the subtree sum. In AVL, the balancing operations are tree rotations.If P is the left child of Qand we are doing a right rotationrooted in Q, then the left subtree of P remains the same, while the left subtree of Q will now be the left subtree of Q minus the left subtree of P and O itself. THe case of left rotation is the same. Hence the left subtree sum values can be maintaine din O(1)
    delete(k): when the deleted element has at most 1 child, we can only need to update the nodes ancestors. If there are two childres, we also need to update elements on the path between the deleted and it's succesor(The element with which we will swap it before deleting) 
    partial-sum(k): because each key stores the sum of left subtree in nodes, we need only to search the element with specified key and update the subtree sum along the way.
*/


