/*3-10. In the bin-packing problem, we are given n metal objects, each weighing between zero and one kilogram. Our goal is to find the smallest number of bins that will hold the n objects, with each bin holding one kilogram at most.
 *
 * The best-fit heuristic for bin packing is as follows. Consider the objects in the order in which they are given. For each object, place it into the partially filled bin with the smallest amount of extra room after the object is inserted.. If no such bin exists, start a new bin. Design an algorithm that implements the best-fit heuristic (taking as input the n weights w1,w2,...,wn and outputting the number of bins used) in O(nlogn) time.
 * Repeat the above using the worst-fit heuristic, where we put the next object in the partially filled bin with the largest amount of extra room after the object is inserted.
 * SOL:
 * We use BST. Finding the smallest bin that can hold this element if all bins are smaller thean this element size, else insert new one.
 * */

min_node = NULL

while node != NULL:
    if node.weight >= w && node.left < w:
        min_node = node
	break
    elif  node.left >= w:
    	node = node.left
    else:
        node = node.right

if min_node == NULL:
    bst.insert(new node(w))
else:
    bst.delete(min_node)
    min_node->weight -= w
    bst.insert(min_node)
