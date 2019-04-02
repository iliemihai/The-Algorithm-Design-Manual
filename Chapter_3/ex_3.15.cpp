/*3-15. Design a data structure that allows one to search, insert, and delete an integer X in O(1) time (i.e., constant time, independent of the total number of integers stored). Assume that 1≤X≤n and that there are m+n units of space available, where m is the maximum number of integers that can be in the table at any one time. (Hint: use two arrays A[1..n] and B[1..m].) You are not allowed to initialize either A or B, as that would take O(m) or O(n) operations. This means the arrays are full of random garbage to begin with, so you must be very careful.
SOL:
init:
    k = 0
insert(x):
    k++;
    A[x] = k;
    B[k] = X;

search(x):
    return (A[x]<k)&&(B[A[x]]==x)

delete(x):
    A[B[k]] = A[x];
    B[A[x]] = B[k];
    k--;
 */
