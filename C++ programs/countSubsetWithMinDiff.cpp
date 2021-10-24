#include<bits/stdc++.h>
using namespace std;

int countsdiff(vector<int>arr,int diff,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];

    int req=(sum+diff)/2;

    int t[n+1][diff+1];

    for(int i=1;i<=req;i++)
        t[0][i]=0;
    for(int i=0;i<=n;i++)
        t[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=req;j++)
        {
            if(arr[i]>req)
                t[i][j]=t[i-1][j];
            else
                t[i][j]=t[i-1][j] + t[i-1][j-arr[i-1]];

        }
    }

    return t[n][req];
}

int main()
{
    vector<int>arr={1,1,2,3};
    int diff=1;
    int n=arr.size();

    cout<<countsdiff(arr,diff,n);
}
