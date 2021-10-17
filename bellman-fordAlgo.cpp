#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

ll mD(vector<ll>&d){
    ll md=1e8, mv = -1;
    for(ll i=0 ; i<d.size() ; i++){
        if(md>d[i]){
            md=d[i];
            mv = i;
        }
    }
    return mv;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, e, u, v, w, src, des;
        cin>>n>>e;
        vector<vector<pair<ll, ll>>> adj(n);
        
        cin>>src>>des;
        src--;	des--;
        for(int i=0 ; i<e ; i++){
            cin>>u>>v>>w;
            adj[u-1].push_back({v-1, w});
        }
        
        vector<ll> d(n, 1e9);
        //vector<bool> vis(n, 0);
        d[src] = 0;
        
        for(ll i=0 ; i<n ; i++){
            ll mv = mD(d);
            if(mv==-1)
                break;
            //vis[mv]=1;
            //cout<<mv<<"\n";
            for(ll j=0 ; j<adj[mv].size() ; j++){
                if(d[adj[mv][j].F]>d[mv]+adj[mv][j].S)
                    d[adj[mv][j].F] = d[mv] + adj[mv][j].S;
            }
        }	
        cout<<d[des]<<"\n";
    }
    return 0;
}
