// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
int x[100][100];
int k=0;
void print(int n,int W)
{
  cout<<"   ";
  for(int w=0;w<=W; w++)
    cout<<w<<"  ";
  cout<<"\n  ----------------"<<endl;
  
  for(int i=0;i<=n; i++){
    cout<<i<<" |";
    for(int w=0;w<=W; w++){
      cout<< x[i][w]<<"  ";
    }
    cout<<endl;
  }
  cout<<"============================"<<endl;
}
void knapsack(int n,int W,int wt[],int p[])
{
  for(int i=0;i<=n; i++) x[i][0]=0;
  for(int i=0;i<=W;i++) x[0][i]=0;
  for(int i=0;i<=n;i++)
  {
    for(int w=0;w<=W;w++)
    {
      if(i==0 || w==0){
        x[i][w]=0;
      }
      else if(wt[i]<=w){
        x[i][w]=max(p[i]+x[i-1][w-wt[i]],x[i-1][w]);
      }
    else{
        x[i][w]=x[i-1][w];
    }
    }
  }
  int total_profit=x[n][W];
  cout<<"Total Profit is: "<<total_profit<<endl;
  int w=W;
  cout<<"Capacity: "<<w<<endl;
  for(int i=n;i>=1;i--)
  {
    if(total_profit==x[i-1][w]){
      continue;
    }
    else{
      cout<<"Item "<<i<<" is included."<<endl;
      w=w-wt[i];
      total_profit=total_profit-p[i];
      if(total_profit==0) break;
    }
  }
  
  print(n,W);
}
int main()
{
  int n,W;
  n=8;W=12;
  int p[]={0,100,20,50,30,60,10,70,80}; //*starting from index 1
  int wt[]={0,5,4,3,2,1,3,2,3};
  knapsack(n,W,wt,p);
  return 0;
}