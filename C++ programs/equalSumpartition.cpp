#include<bits/stdc++.h>
using namespace std;

bool equalsum(vector<int> arr, int n)
{
    int arrsum=0;
    for(int i=0;i<n;i++)
        arrsum+=arr[i];
    if(arrsum%2!=0)
        return false;
    else
    {
      int sum=arrsum/2;
      bool t[n+1][sum+1];

      for(int i=1;i<=sum;i++)
            t[0][i]=false;
      for(int i=0;i<=n;i++)
        t[i][0]=true;

      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=sum;j++)
          {
              if(arr[i-1]>j)
                t[i][j]=t[i-1][j];
              else
                t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];

          }
      }

      return t[n][sum];
    }
}

int main()
{
    vector<int> arr={1,5,11,5};
    int n=arr.size();

    if(equalsum(arr,n))
        cout<<"true";
    else
        cout<<"false";

    return 0;
}
