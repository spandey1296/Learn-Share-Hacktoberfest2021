#include <iostream>
using namespace std;

//{12,18,20,42,8,10}, find key=8 by linear search

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++) //traversing of the array 
    {
        if (arr[i] == key)
        {
            return i; 
        }
    }
    return -1;
}
// becoz of n time loop, the time complexity will be o(n) 

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;


   cout<<linearSearch(arr, n , key);
    return 0;
}
