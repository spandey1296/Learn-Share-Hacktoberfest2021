#include <bits/stdc++.h>
#include <iostream>

#include <iostream>
using namespace std;
#define MAX 100

class Stack
{
  int arr[MAX];
  int top;

public:
  Stack()
  {
    top = -1;
  }
  bool isFull()
  {
    if (top == MAX - 1)
      return true;
    else
      return false;
  }
  bool isEmpty()
  {
    if (top == -1)
      return true;
    else
      return false;
  }
  void push(int item)
  {
    top++;
    arr[top] = item;
  }
  void pop()
  {
    // int x = arr[top];
    top--;
    // return x;
  }
  int peak()
  {
    return arr[top];
  }
};
using namespace std;
const int v = 7;
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
  Stack s;
  s.push(a);
  visited[a] = 1;
  int vis;
  while (!s.isEmpty())
  {
    vis = s.peak();
    cout << vis+1 << " ";
    s.pop();
    int neighbor_Vertex;
    while ((neighbor_Vertex = unvisitedNeighbor(vis,graph,visited)) != -1)
    {
      //Mark neighbors as visited
      visited[neighbor_Vertex] = 1;
      s.push(neighbor_Vertex);
    }
  }
}
int main()
{
  ifstream infile;
  infile.open("dfs_adj_matrix.txt", ios::in);
  int graph[v][v];
  for (int i = 0; i < v; i++)
    for (int j = 0; j < v; j++)
      infile >> graph[i][j];

  bfs(graph, 0);
  return 0;
}
/**
0 1 1 0 1 0 0
1 0 0 1 0 1 0
1 0 0 1 0 0 1
0 1 1 0 1 0 0
1 0 0 1 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0 
**/