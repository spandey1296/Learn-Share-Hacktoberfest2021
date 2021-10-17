#include <bits/stdc++.h>
using namespace std;

#define nwl cout<<"\n"
#define V(type) vector<type>
#define rep(i, a, b) for(ll i=a ; i<b ; i++)
#define R return
#define F first
#define S second
#define BG begin()
#define E end()
#define pub push_back
#define pob pop_back
#define IMX INT_MAX
#define IMN INT_MIN
#define LMX LONG_MAX
#define LMN LONG_MIN

const int mod = 1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;

void FAST(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void fileIO(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

V(V(ll)) matmul(V(V(ll)) A, V(V(ll)) B){
	ll m= A.size(), r = B.size(), n=B[0].size();
	V(V(ll)) C(m, V(ll)(n, 0));
	for(ll i=0 ; i<m ; i++){
		for(ll j=0 ; j<n ; j++){
			for(ll k=0 ; k<r ; k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	R C;
}

V(V(ll)) Mpow(V(V(ll)) m, ll n){
	ll s = m.size();
	V(V(ll)) res(s, V(ll)(s, 0));
	for(ll i=0 ; i<s ; i++) res[i][i] = 1;
	
	while(n>0){
		if(n&1)
			res = matmul(res, m);
		n >>= 1LL;
		m = matmul(m, m);
	}
	return res;   
}

ll gcd(ll a, ll b){
	while(b>0){
		a %= b;
		swap(a, b);
	}
	return a;
}

ll gcd_extend(ll a, ll b, ll& x, ll& y){
	if(b==0){
		x = 1;
		y=0;
		R a;
	}
	ll x1, y1;
	ll g = gcd_extend(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1*(a/b);
	R g;
}

bool isPrime(ull n){
	if(n<=1)	R 0;
	if(n<=3 || n==5)	R 1;
	if(n%2==0 || n%3==0 || n%5==0)
		R 0;
	for(ll i=5 ; i*i<=n ; i+=6)
		if(n%i==0 || n%(i+2)==0)
			R 0;
	R 1;
}

void sieve(ll n){
	V(bool) v(n, 1);
	for(ll i=0 ; i*i<=n ; i++){
		if(v[i]){
			for(ll j=i*i ; j<n ; j+=i){
				v[j] = 0;
			}
		}
	}
}

V(ll) factorize(ll n){
	V(ll) f;
	while(n%2==0){
		n/=2;
		f.pub(2);
	}
	while(n%3==0){
		n/=3;
		f.pub(3);
	}
	for(ll i=5 ; i*i<=n ; i+=6){
		while(n%i==0){
			n/=i;
			f.pub(i);
		}
		while(n%(i+2)==0){
			n/=(i+2);
			f.pub((i+2));
		}
	}
	cout<<n;
	nwl;
	if(n>1)	f.pub(n);
	R f;
}

ll phi(ll n){
	ll res = n;
	while(n%2==0){
		n/=2;
		res -= res/2;
	}
	while(n%3==0){
		n/=3;
		res -= res/3;
	}
	for(ll i=5 ; i*i<=n ; i+=6){
		while(n%i==0){
			n/=i;
			res -= res/i;
		}
		while(n%(i+2)==0){
			n/=(i+2);
			res -= res/(i+2);
		}
	}
	if(n>1)	res -= res/n;
	R res;
}

void phi_1_to_n(ll n){
	V(ll) phi(n+1);
	phi[0] = 0;
	phi[1] = 1;
	for(ll i=2 ; i<=n ; i++)
		phi[i] = i;
	for(ll i=2 ; i<=n ; i++){
		if(phi[i]==i){
			for(ll j=i ; j<=n ; j+=i)
				phi[i] -= phi[i]/i;
		}
	}
}

//applying digit dp
// dp[i][j][k] represents the position of the sum of 
//digits till position i having tight sum or not and 
//having sum equal to k
ll dp[20][2][200];
vector<ll> num;

void fillnum(ll n){
	num.clear();
	while(n){
		num.pub(n%10);
		n/=10;
	}
	reverse(num.begin(), num.end());
}

//recursion+memoization
ll rec(ll pos, ll f1, ll sum){
	if(pos==num.size())	return sum;

	ll&ret = dp[pos][f1][sum];
	if(ret!=-1)
		return ret;

	ll lim = f1?num[pos]:9;
	ll ans = 0;
	for(ll i=0 ; i<=lim ; i++){
		ans += rec(pos+1, i<num[pos]?0:f1, sum+i);
	}

	return ret = ans;
}


int main(){
	FAST();
	fileIO();
	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;

		fillnum(b);
		memset(dp,-1,sizeof(dp));
		ll n1 = rec(0,1,0);

		fillnum(a-1);
		memset(dp,-1,sizeof(dp));
		ll n2 = rec(0,1,0);

		cout<<n1-n2<<"\n";
	}
	R 0;
}
