// __Davit__
#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()

using namespace std;
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;

// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);
vector<bool> sieve(ll n) {
    vector<bool> v(n + 1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (v[i]) {
            for (ll j = i * i; j <= n; j += i) v[j] = false;
        }
    }
    return v;
}


int main() {


}

