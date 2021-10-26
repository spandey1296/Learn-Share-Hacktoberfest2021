#include<iostream>
using namespace std;
//binary search --> key = 27, {8,10,12,21,27,34,42}

int binarySearch(int arr[], int n , int key)
{
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]>key)
        {
            e=mid-1;
        }
        else 
        {
            s=mid+1;
        }
    }
    return -1;
}


int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
     
     int key;
     cin>>key;


cout<<binarySearch(arr,n, key);
return 0;
}

/*
time complexity 

after first iteration, lenght of array -->n
after second iteration, lenght of array becomes n/2
after the k iterations, length of array will becomes n/2^k

let the array becomes 1 after k iterations


n/2^k=1
n=2^k
log2(n)=log2(2^k)
log2(n)=k log 2(2)
k=log2(n)

therefore, time complexity will be O(log2(n)), this is less than O(n), as this is of linear search 


hence, the binary search is less time consuimg then binary search
*/  
