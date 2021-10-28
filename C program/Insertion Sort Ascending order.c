#include<stdio.h>
void insertionsort(int a[],int size);
int main(){
    int i,j,size;
    printf("Enter number of elements\n");
    scanf("%d",&size);
    int a[size];
    printf("Enter numbers\n");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    insertionsort(a,size);
    printf("Ascending oreder of given numbers is\n");
    for(i=0;i<size;i++){
        printf("%d\n",a[i]);
    }
}
void insertionsort(int a[],int size){
    int temp,i,j;
    for(i=1;i<size;i++){
        j=i;
        while((a[j]<a[j-1])&&j>0){
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }
    }
}