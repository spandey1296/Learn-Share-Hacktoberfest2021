#include<bits/stdc++.h>
using namespace std;

vector<int>subsetsum(vector<int>arr,int n,int range)
{
    int t[n+1][range+1];
    for(int i=1;i<=range;i++)
        t[0][i]=0;
    for(int i=0;i<=n;i++)
        t[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(arr[i-1]>range)
                t[i][j]=t[i-1][j];
            else
                t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];

        }
    }
    vector<int> v;
    for(int i=n;i<n+1;i++)
    {for(int j=0;j<=range/2;j++)
        if(t[i][j]==1)
            v.push_back(j);
    }

    return v;
}

int mindiff(vector<int>arr,int n)
{
    int range=0;
    for(int i=0;i<n;i++)
        range+=arr[i];
    vector<int>v;
    v=subsetsum(arr,n,range);
    int mn=INT_MAX;
    for(int i=0;i<v.size();i++)
        mn=min(mn,range-(2*v[i]));

    return mn;
}



int main()
{
    vector<int> arr={1,6,11,5};
    int n=arr.size();

    cout<<mindiff(arr,n);
}
