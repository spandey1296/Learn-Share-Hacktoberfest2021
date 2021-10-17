#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

ll mW(vector<ll>& d, vector<bool>&vis){
	ll mw = 1e8, mwv=-1;
    for(ll i=0 ; i<d.size() ; i++){
        if(!vis[i] && mw>d[i]){
            mw = d[i];
            mwv = i;
        }
    }
    
    return mwv;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, e, u, v, w;
        cin>>n>>e;
        
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0 ; i<e ; i++){
            cin>>u>>v>>w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<ll> d(n, 1e8);
        vector<bool> vis(n, 0);
        
        d[0] = 0;
        for(ll i=0 ; i<n ; i++){
            ll mv = mW(d, vis);
            vis[mv]=1;
            for(ll j=0 ; j<adj[mv].size() ; j++){
                if(!vis[adj[mv][j].F] && d[adj[mv][j].F]>adj[mv][j].S){
                    d[adj[mv][j].F] = adj[mv][j].S;
                }
            }
        }
        
        ll wt = 0;
        for(auto x: d)
            wt+=x;
        cout<<wt<<"\n";
    }
    // write your code here
    return 0;
}
