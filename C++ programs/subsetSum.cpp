#include<bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int>arr,int sum,int n)
{
    bool t[n+1][sum+1];
     for(int i=0;i<=n;i++)
        t[i][0]=true;
    for(int i=1;i<=sum;i++)
        t[0][i]=false;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
                t[i][j]=t[i-1][j];
            else
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];

        }
    }
    return t[n][sum];
}

int main()
{
    vector<int>arr={2,3,7,8,10};
    int sum=11;
    int n=arr.size();
  if(subsetsum(arr,sum,n))
    cout<<"true";
    else
        cout<<"false";



    return 0;
}
