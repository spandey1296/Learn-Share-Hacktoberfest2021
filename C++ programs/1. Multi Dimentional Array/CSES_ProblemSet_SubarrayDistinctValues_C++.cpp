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
	cin.tie(nullptr);
	cout.tie(nullptr);
}

void TIME(){
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	cout<<"\n Elapset time in milliseconds : "
		<<chrono::duration_cast<chrono::milliseconds>(end-start).count()
		<<"ms\n";
	nwl;
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


int main(){
	FAST();
	fileIO();
	ll n, x, i=0, j=0, cnt=0, s=0;
	cin>>n>>x;
	V(int) v(n);
	for(auto &p : v)
		cin>>p;

	map<int, int> mp;

	while(j<n){
		if(mp[v[j++]]++==0)
			cnt++;
		while(cnt>x){
			if(--mp[v[i++]]==0)
				cnt--;
		}
		s += (j-i);
	}

	cout<<s;
	nwl;
	R 0;
}
