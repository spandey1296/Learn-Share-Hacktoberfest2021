#include <iostream>
using namespace std;

bool issorted(int arr[], int n)
{
     if (n == 0 || n == 1)
          return true;

     if (arr[0] > arr[1])
          return false;

     return issorted(arr + 1, n - 1);
}

bool issorted2(int arr[], int n)
{
     if (n == 0 || n == 1)
          return true;

     bool small = issorted(arr + 1, n - 1);

     if (!small)
          return false;

     if (arr[0] > arr[1])
          return false;
     else
          return true;
}

bool issorted3(int arr[], int n)
{
     if (n == 0 || n == 1)
          return true;

     if (arr[n - 2] > arr[n - 1])
          return false;

     return issorted(arr, n - 1);
}

int main()
{
     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
     // cout << issorted(arr, 8) << endl;
     // cout << issorted2(arr, 8) << endl;
     cout << issorted3(arr, 8) << endl;
}
