#include <iostream>
#include <vector>
using namespace std;
/*Because it is a set, elements do not repeat. In this case we asume that there is only one sequence on numbers which sums to k.
The magical black box has expnential worst time (NP-complete)
isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) ||
                           isSubsetSum(set, n-1, sum-set[n-1])
isSubsetSum(set, n, sum) = false if sum > 0 && n == 0
isSubsetSum(set, n, sum) = true if sum == 0

Pseudocode k sum:

    S = {a_1, a_2, a_3,...a_n}
    S_final = {}
    for i in (1,n)
        if black_box(S - {a_i}) is False
            S_final += a_i

    return S_final
*/

//this is O(exp(2))
bool isSubsetSum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0 && sum > 0)
        return false;
    //if last element is greater than sum, ignore it
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);
    // else check if sum can be obtained by any of the following
    // a)including the last element
    // b)excluding the last element
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

//pseudo polynomial time DP
//2D table subset[][] where subset[i][j] == true if there is subset set[0..j-1]  whith sum equal to i, otherwise false. Return subset[sum][n]
bool isSubsetSum_DP(int set[], int n, int sum)
{
    bool subset[n+1][sum+1];
    //sum is 0, answer is true
    for (int i=0; i<n+1; i++)
        subset[i][0] = true;
    //sum is not 0, set is empty, false
    for (int i=1; i<sum+1; i++)
        subset[0][i] = false;
    //fill subset bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if (j < set[i-1])
                subset[i][j] = subset[i-1][j];
            else if (j >= set[i-1])
                subset[i][j] = subset[i-1][j] ||
                               subset[i-1][j-set[i-1]];
        }
    }
    return subset[n][sum];
}


int main()
{
    vector<int> S = {3, 34, 4, 12, 5, 2};
    int set[5];
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);
    vector<int> subset;
    for (int i=0; i<n; i++)
    {
        vector<int> S = {6, 34, 4, 12, 5, 2};
        int erased = S[i];
        S.erase(S.begin() + i);
        copy(S.begin(), S.end(), set);
        
        if (isSubsetSum(set, n-1, sum)==false)
            subset.push_back(erased);
}
    cout << "Subset with sum "<< sum <<" is ";
    for (int i=0; i<subset.size(); i++)
        cout  << subset[i] << " "; 
    cout << endl;
}
