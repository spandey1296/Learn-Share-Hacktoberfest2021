#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

ll mD(vector<ll>&d, vector<bool>&vis){
    ll md=1e8, mv=-1;
    for(ll i=0 ; i<d.size() ; i++){
        if(!vis[i] && md>d[i]){
            md = d[i];
            mv=i;
        }
    }
    
    return mv;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m, u, v, w;
        cin>>n>>m;
        vector<vector<pair<ll, ll>>> adj(n);
        
        for(ll i=0 ; i<m ; i++){
            cin>>u>>v>>w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<ll> d(n, 1e8);
        vector<bool> vis(n, 0);
        d[0] = 0;
        
        for(int i=0 ; i<n ; i++){
            ll mv = mD(d, vis);
            vis[mv] = 1;
            
            for(ll j=0 ; j<adj[mv].size() ; j++){
                if(!vis[adj[mv][j].F] && d[adj[mv][j].F]>adj[mv][j].S+d[mv])
                    d[adj[mv][j].F] = adj[mv][j].S+d[mv];
            }
        }
        
        for(ll i=0 ; i<n ; i++){
            cout<<i<<" "<<d[i]<<"\n";
        }
    }
    return 0;
}
