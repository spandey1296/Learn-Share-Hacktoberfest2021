#include<stdio.h>
#include<conio.h>
#define MAX 5
struct circularQueue
{
    int ele[MAX];
    int front,rear;
};
typedef struct circularQueue CIRCULARQUEUE;
CIRCULARQUEUE cq;

void enqueue(int x);
int dequeue(void);
void traverse(void);
int peek(void);

int main()
{
    cq.front=-1;
    cq.rear=-1;
    int choice=1,num1;
    printf("Circular Queue Operation\n");
    while(choice)
    {
        printf("\n..........\n");
        printf("1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Peek Operation\n");
        printf("4. Traverse Operation\n");
        printf("5. Exit");
        printf("..........\n");
        int num;
        printf("Enter your choice : ");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
                printf("Enter the number to enqueue : ");
                scanf("%d",&num1);
                enqueue(num1);
                break;
            case 2:
                num1=dequeue();
                printf("The dequeued element is %d",num1);
                break;
            case 3:
                printf("The element with Peek operation is %d",peek());
                break;
            case 4:
                traverse();
                break;
            case 5:
                return;
        }
    }
    return 0;
}
void enqueue(int x)
{
    if(cq.front==0&&cq.rear==MAX-1||cq.front==cq.rear+1)
    {
        printf("Queue overflow\n");
    }
    else if(cq.front==-1)
    {
        cq.front=0;
        cq.rear=0;
    }
    else if(cq.rear==MAX-1)
    {
        cq.rear=0;
    }
    else
    {
        cq.rear=cq.rear+1;
    }
    cq.ele[cq.rear]=x;
}
int dequeue(void)
{
    int num;
    if(cq.front==-1)
    {
        printf("Queue underflow\n");
        return -1;
    }
    num=cq.ele[cq.front];
    if(cq.front==cq.rear)
    {
        cq.front=-1;
        cq.rear=-1;
    }
    else if(cq.front==MAX-1)
    {
        cq.front=0;
    }
    else
    {
        cq.front=cq.front+1;
    }
    return num;
}
int peek(void)
{
    if(cq.front==-1)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
        return cq.ele[cq.front];
}
void traverse(void)
{
    if(cq.front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if(cq.front<=cq.rear)
        {
            for(int i=cq.front;i<=cq.rear;i++)
            {
                printf("%d ",cq.ele[i]);
            }
        }
        else
        {
            for(int i=cq.front;i<MAX;i++)
            {
                printf("%d ",cq.ele[i]);
            }
            for(int i=0;i<=cq.rear;i++)
            {
                printf("%d ",cq.ele[i]);
            }
        }
    }
}
