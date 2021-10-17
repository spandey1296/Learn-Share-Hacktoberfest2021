#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

ll find(vector<ll>&p, ll v){
    if(p[v]==v)
        return v;
    return p[v] = find(p, p[v]);
}

bool C(vector<ll>& p, vector<ll> &r, ll v1, ll v2){
    ll p1 = find(p, v1);
    ll p2 = find(p, v2);
    if(p1==p2)	return 0;
    if(r[p1]==r[p2]){
        p[p2] = p1;
        r[p1]++;
    }
    else if(r[p1]>r[p2])
        p[p2] = p1;
    else
        p[p1] = p2;
    return 1;
}

int main(){
    // write your code here
    ll t;
    cin>>t;
    while(t--){
        ll v,e;
        cin>>v>>e;
        
        vector<pair<ll, pair<ll, ll>>> gr(e);
        for(ll i=0 ; i<e ; i++){
            cin>>gr[i].S.F>>gr[i].S.S>>gr[i].F;
        }
        
        sort(gr.begin(), gr.end());
        
        vector<ll> p(v);
        vector<ll> r(v, 1);
        for(int i=0 ; i<v ; i++)
            p[i]= i;
        
        ll w=0, c=0;
        for(ll i=0; i<e && c<v-1; i++ ){
            if(C(p, r, gr[i].S.F, gr[i].S.S)){
                w+=gr[i].F;
                c++;
            }
        }
        cout<<w<<"\n";
    }
    
    return 0;
}
