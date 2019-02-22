#include <iostream>
#include <stdio.h>

#define MAX 1000
#define INF 10000
int M[MAX];

void CreateTree(int node, int start, int end, int A[], int N)
{
    if (start == end)
    {
        M[node] = start;
    }
    else 
    {
        CreateTree(2*node+1, start, (start+end)/2, A, N);
        CreateTree(2*node+2, (start+end)/2+1, end, A, N);

        if (A[M[2*node+1]] < A[M[2*node+2]])
            M[node] = M[2*node+1];
        else
            M[node] = M[2*node+2];
    }
}

int RMQ_ST(int node, int start, int end, int s, int e, int A[])
{
    if (s <= start && e >= end)
        return M[node];
    else if (s > end || e < start)
        return INF;

    int q1 = RMQ_ST(2*node+1, start, (start+end)/2, s, e, A);
    int q2 = RMQ_ST(2*node+2, (start+end)/2+1, end, s, e, A);

    if (q1 == INF)
        return q2;
    else if (q2 == INF)
        return q1;

    if (A[q1] < A[q2])
        return q1;

    return q2;
}

int main()
{
    int A[10] = {1,5,-1,2,6,3,1,8,9,20};
    CreateTree(0,0,10-1,A,10);
    int s=0,e=4;
    printf("Minimul este %d\n", A[RMQ_ST(0,0,10-1,s,e,A)]);
    return 0;
}
