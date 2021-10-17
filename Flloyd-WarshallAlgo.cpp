#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

int main(){
    // write your code here
    ll t;
    cin>>t;
    while(t--){
        ll n,e;
        cin>>n>>e;
        vector<vector<ll>> dp(n, vector<ll>(n, 1e9));

        for(ll i=0 ; i<e ; i++){
            ll a,b,w;
            cin>>a>>b>>w;
            if(dp[a-1][b-1]>w){
            	dp[a-1][b-1] = w;
            }
            if(dp[b-1][a-1]>w){
            	dp[b-1][a-1] = w;
            }
        }
        
        for(ll i=0 ; i<n ; i++)
            dp[i][i] = 0;

        for(ll k=0 ; k<n ; k++){
            for(ll i=0 ; i<n ; i++){
                for(ll j=0 ; j<n ; j++){
                    if(dp[i][k]!=1e9 && dp[k][j]!=1e9 && dp[i][j]>(dp[i][k]+dp[k][j])){
                        //cout<<i<<" "<<j<<"\n";
                        dp[i][j] = dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        
        ll q;
        cin>>q;
        while(q--){
            ll x,y;
            cin>>x>>y;
            cout<<dp[x-1][y-1]<<"\n";
        }
    }
    return 0;
}
