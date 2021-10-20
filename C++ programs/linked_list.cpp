#include <iostream>
using namespace std;

// creating a node
struct Node
{
    int data;
    struct Node *next;
};

//creating a head Node
struct Node *head = NULL;

//creating nodes of ll
void Create(int a[], int n)
{
    //creting a first node of ll
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = NULL;
    last = head;

    //creating other nodes of ll
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//displaying nodes of ll
void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

//displaying of nodes rec
int RDisplay(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        RDisplay(p->next);
    }
    return 0;
}

//dispaling nodes reverse using recursion
int RRDisplay(struct Node *p)
{
    if (p)
    {
        RRDisplay(p->next);
        cout << p->data << " ";
    }
    return 0;
}

//counting number of element in a ll using loop
int Count(struct Node *p)
{
    int count = 0;

    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

//counting number of element in a ll using rec
int RCount(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return RCount(p->next) + 1;
}

//sum of element using loop
int Sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//sum of elements using recursion
int RSum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return RSum(p->next) + p->data;
}

// max element of the ll using loop
int Max(struct Node *p)
{
    int max = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

//max element using rec
int RMax(struct Node *p)
{
    int x = 0;
    if (p == NULL)
    {
        return INT32_MIN;
    }
    x = RMax(p->next);
    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

//searching in a ll
Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// searching in ll using rec
Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data == key)
    {
        return p;
    }
    else
    {
        return RSearch(p->next, key);
    }
}

//improvising linear search
Node *ISearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{

    int a[] = {1, 2, 32, 4, 5};
    int size = sizeof(a) / sizeof(int);
    Create(a, size);

    //display functions
    // Display(head);
    // RDisplay(head);
    // RRDisplay(head);

    // count functions
    // cout<<Count(head);
    // cout << RCount(head);

    //sum function
    // cout<<Sum(head);
    // cout<<RSum(head);

    //max function
    // cout << Max(head);
    // cout << RMax(head);

    //search function
    //linear search loop
    // struct Node *temp = Search(head, 5);
    // if (temp != NULL)
    // {
    //     cout << "key is found: " << temp->data << endl;
    //     cout << "key's address is : " << temp->next << endl;
    // }
    // else
    // {
    //     cout << " key is not found";
    // }

    //linear search rec
    // struct Node *temp = RSearch(head, 32);
    // if (temp != NULL)
    // {
    //     cout << "key is found: " << temp->data << endl;
    //     cout << "key's address is : " << temp->next << endl;
    // }
    // else
    // {
    //     cout << " key is not found";
    // }

    //improvising linear search
    Display(head);
    struct Node *temp = ISearch(head, 32);
    struct Node *temp2 = ISearch(head, 4);
    if (temp != NULL)
    {
        cout << "key is found: " << temp->data << endl;
        cout << "key's address is : " << temp->next << endl;
    }
    else
    {
        cout << " key is not found";
    }
    Display(head);
}
