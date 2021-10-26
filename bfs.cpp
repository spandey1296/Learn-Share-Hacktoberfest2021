#include <iostream>
#include <queue>
using namespace std;
class Graph{
    bool **arr;
    int size;
public:
    Graph(int n){
        size = n;
        arr = new bool *[n];
        for(int i=0;i<n;i++)
            arr[i] = new bool[n]{false};
    }
    ~Graph(){
        for (int i = 0; i < size;i++)
            delete[] arr[i];
        delete[] arr;
    }
    void bfs(int start);
    void createGraph();
};
void Graph::createGraph(){
    int a, b;
    while(true){
        cout << "Enter edge vertex from start->end\n";
        cin >> a >> b;
        if(a==-1 && b==-1)
            break;
        a--;b--;
        if(a<size && b<size){
            arr[a][b] = true;
        }
    }
}
void Graph::bfs(int start){
    cout << "BFS : ";
    start--;
    queue<int> q;
    int temp;
    bool visited[size] = {false};
    q.push(start);
    cout << start+1 << " ";
    visited[start] = true;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i=0;i<size;i++){
            if(arr[temp][i] && !visited[i]){
                cout << i+1 << " ";
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    int n;
    cout << "Enter number of vertices\n";
    cin >> n;
    Graph g = Graph(n);
    g.createGraph();
    int start;
    cout << "Enter start of graph\n";
    cin >> start;
    g.bfs(start);
    return 0;
}
