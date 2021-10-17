//Implementation of disjoint set union data structure 
//with path compression & union by rank optimisations


#include<bits/stdc++.h>
using namespace std;

void make_set(vector<int> &rep, int v){
	rep[v] = v;
	rank[v] = 0;
}

//Path Compression Optimisation
int find(vector<int> &rep, int v){
	// if(rep[v]==v)
	// 	return v;
	// rep[v] = find(rep, rep[v]);
	// return rep[v];

	vector<int> list;
	while(1){
		if(rep[v]==v)
			break;
		list.push_back(v);
		v = rep[v];
	}
	for(auto n: list)
		rep[n] = v;
	return v;
}

//Union by rank optimisation
void union(vector<int> &rep, vector<int>& rank, int a, int b){
	a = find(rep, a);
	b = find(rep, b);
	if(a!=b){
		if(rank[a]<rank[b])
			swap(a, b);
		rep[b] = a;
		if(rank[a]==rank[b])
			rank[a]++;
	}
}

void disunion(int nroot, vector<bool>& rm){
	int p;
  	for(int i=0;i<N;++i)find(i);
	for(int i=0;i<N;++i){
		p=find(i);
		if(rm[p]&&!rm[i]){
			par[p]=i;
			par[i]=i;
		}
	}
	for(int i=0;i<N;++i)find(i);
	for(int i=0;i<N;++i){
		if(rm[i]){
			par[i]=nroot;
			rm[i]=0;
		}
	}
	memset(rnk,0,sizeof(rnk));
	for(int i=0;i<N;++i){
		p=getPar(i);
		if(p!=i)rnk[p]=1;
	}
 }

int main(){
	
	return 0;
}
