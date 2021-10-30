#include <iostream>
using namespace std;

int sum_array(int arr[], int n)
{

     if (n == 0)
          return 0;

     int small = sum_array(arr + 1, n - 1);
     return small + arr[0];
}

int sum_array3(int arr[], int n)
{

     if (n == 0)
          return 0;

     int small = sum_array(arr + 1, n - 1);
     return small + arr[0];
}

int sum_array2(int arr[], int n)
{

     if (n == 0)
          return 0;

     return arr[n - 1] + sum_array2(arr, n - 1);
}

int main()
{
     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
     cout << sum_array2(arr, 8);
     // cout << sum_array(arr, 8);
     // cout << sum_array3(arr, 8);
}
