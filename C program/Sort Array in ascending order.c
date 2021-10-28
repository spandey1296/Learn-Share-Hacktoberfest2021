#include<stdio.h>
main(){
    int i,j,num,temp;
    printf("Enter number of elements\n");
    scanf("%d",&num);
    int a[num];
    printf("Enter numbers\n");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<num;i++){
        for(j=i+1;j<num;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }   

        }

    }
    printf("Ascending order of given numbers is\n");
    for(i=0;i<num;i++){
        printf("%d\n",a[i]);
    }
}