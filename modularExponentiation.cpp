#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fastExpo(ll a, ll b, ll mod) //a=>base , b=>power
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) //if the last bit is set
        {
            res = (a * res);
        }
        a = (a * a);
        b = b >> 1;
    }
    return res;
}

int power(int a, int n)
{
    if (n == 0)
        return 1;
    int subproblem = pow(a, n / 2);
    if (n & 1)
        return a * subproblem * subproblem;
    else
        return subproblem * subproblem;
}
int main()
{
    ll a, b, m;
    cin >> a >> b >> m;
    ll res = fastExpo(a, b, m);
    cout << res << endl;
    return 0;
}
