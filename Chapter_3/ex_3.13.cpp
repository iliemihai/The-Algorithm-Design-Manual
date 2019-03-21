#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX 100

//O(logN)
void update(int BIT[], int len, int x, int val)
{
	//index in BIT is index ina arr + 1
	x += 1;
    //travel all ancestors
	while (x <= len)
	{
		//add val to current node in BIT
		BIT[x] += val;
        //update index
        x += x&-x;
    }
}

//o(logN)
int query(int BIT[], int x)
{
	int sum = 0;
	x += 1;

	while (x > 0)
	{
		//add crt element in BIT to sum
		sum += BIT[x];
        //go to next element of sum
		x -= x&-x;
	}
	return sum;
}

//is O(NlogN)
int *constructBIT(int arr[], int n)
{
	int *BIT = (int*) malloc((n+1)*sizeof(int));
	for (int i=1; i<=n; i++)
		BIT[i] = 0;

	for (int i=0; i<n; i++)
		update(BIT, n, i, arr[i]);

	return BIT;
}

int main()
{
	int a[]={2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);
    int *BIT = constructBIT(a, n);
    int index = 6;
	printf("Suma primelor %d elemente este %d\n",index+1, query(BIT, index) );
}