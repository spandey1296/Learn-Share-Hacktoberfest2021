#include<iostream>
using namespace std;
// problem: given an array[] of size n. output sum of each subarray of the given array

// eg: [1,2,2]
// subarrays : [1][1,2][1,2,2][2][2,2][2]
     //Sum:     1   3     5    2   4   2

/*
Approach: 1.Iterate over all the subarrays
       2.nested loop:
             for every i=0 to i=n-1
               for every j=i to j=n-1
                 output sum[i....j]
*/
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
int curr=0;
for(int i=0;i<n;i++)
{curr=0;
for(int j=i;j<n;j++)
{
    curr+=a[j];
    cout<<curr<<endl;
}}
return 0;
}
