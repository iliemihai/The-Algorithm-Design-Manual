//because we use a set of elements we do not have duplicates, and so the data structure can be a bit array

#include<iostream>
#include<bitset>
#include<map>
#include<vector>
using namespace std;

//in case duplicates are allowed, things get more complicated
//use an array with  hash-map of (elements, array index)
//insertion(value) : insert elements in array, and lets say index is k. Set hashmap[value] = k
//delete(value) : replace cell that contains value in array with the last elements in array. Let's say that L is the last elements in array at index N. From previous hasmap[value] is k, the index in the array of the value to be removed. We set array[k]=L, hashmap[N]=k(updated position of last in hashmap) decrease size of array with 1 and remove value from hashmap.
//search(value) : hashmap search(value)

void insert(map<int, int>& hash, int index, int val)
{
    hash[val]=index;
}

int search(map<int, int>& hash, int val)
{
    return hash.find(val) != hash.end();
}

void delete_(map<int, int>& hash, int val)
{
    hash.erase(val);
}



int main()
{
    //Nu duplicated -> bit array
    //search for 5
    bitset<10> x;
    //insertion in O(1)
    x[5] = 1;
    //deletion in O(1)
    x[7] = 0;
    //search in O(1)
    if (x[5] == 1)
        cout << "Found 5!\n";

    cout << x << endl;

    //duplicated
    map<int, int> hash;
    vector<int> arr(12);
    arr[0] = 7;
    insert(hash, 0, 7);
    insert(hash, 1123, 9999);
    search(hash, 7);
    delete_(hash, 7);

    for(map<int, int>::iterator it =hash.begin(); it != hash.end(); it++)
        cout << "value " << it->first << " index " << it->second << endl;
}
