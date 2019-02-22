#include <iostream>
#include <stdio.h>
#define MAX 100
/*Dynamic programming solution
  M[i][j] = j if A[j] < A[M[i][j-1]]
            M[i][j-1] otherwise
*/

int M[MAX][MAX];

void RMQ_DP(int A[], int N)
{
    for (int i=0; i<N; i++)
    {
        M[i][i] = i;
    }

    for (int i=0; i<N; i++)
        for (int j=i+1; j<N; j++)
            if (A[j] > A[M[i][j-1]])
                M[i][j] = M[i][j-1];
            else
                M[i][j] = j;
}

int main()
{
    int A[10] = {3,2,0,-1,5,9,7,6,11,19};
    RMQ_DP(A, 10);
    printf("Elementul minim este %d\n",A[M[1][5]]);
    return 0;
}
