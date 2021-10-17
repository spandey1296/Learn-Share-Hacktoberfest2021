#include <bits/stdc++.h>
#include <iostream>
#define MAX 30
class Queue
{
  int arr[MAX];
  int front;
  int rear;
public:
  Queue()
  {
    front = -1;
    rear = -1;
  }
  void enQueue(int item)
  {
    rear++;
    arr[rear] = item;
  }
  void deQueue()
  {
    front++;
    // return arr[front];
  }
  int peak()
  {
    return arr[front+1];
  }
  int isFull()
  {
    if (rear == MAX - 1)
      return 1;
    else
      return 0;
  }
  int isEmpty()
  {
    if (front == rear)
      return 1;
    else
      return 0;
  }
  void display()
  {
    for (int i = rear; i >= front + 1; i--)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};
using namespace std;
const int v = 6;
int unvisitedNeighbor(int index,int graph[v][v],int visited[]){
    for(int i=0; i<v; i++){
      if(graph[index][i] == 1 && (visited[i] == 0)){
        return i;
      }
    }
    return -1;
  }
void bfs(int graph[v][v], int a)
{
  int visited[v];
  for (int i = 0; i < v; i++)
    visited[i] = 0;
  Queue q;
  q.enQueue(a);
  visited[a] = 1;
  int vis;
  while (!q.isEmpty())
  {
    vis = q.peak();
    cout << vis << " ";
    q.deQueue();
    int neighbor_Vertex;
    while ((neighbor_Vertex = unvisitedNeighbor(vis,graph,visited)) != -1)
    {
      //Mark neighbors as visited
      visited[neighbor_Vertex] = 1;
      q.enQueue(neighbor_Vertex);
    }
  }
}
int main()
{
  ifstream infile;
  infile.open("bfs_adj_matrix.txt", ios::in);
  int graph[v][v];
  for (int i = 0; i < v; i++)
    for (int j = 0; j < v; j++)
      infile >> graph[i][j];

  bfs(graph, 0);
  return 0;
}
/**
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 1 0
0 1 0 0 1 1
0 1 1 1 0 1
0 0 0 1 1 0
**/