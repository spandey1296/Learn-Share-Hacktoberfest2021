#include <bits/stdc++.h>
using namespace std;
int mini(int arr[],int n){

    if(n<2)return 0;
    int currjump = arr[0];
    int maxjump = arr[0];
    int i=0;
    int jump = 1;
    while (i<n-1)
    {
        maxjump = max(maxjump,i+arr[i]);
        if(currjump == i){
            currjump = maxjump;
            jump++;
        }
        i++;
    }
    return jump;
}
int main(){
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr)/sizeof(int);
    int steps1 = mini(arr,n);
    cout<<steps1<<endl;
    return 0;
}
