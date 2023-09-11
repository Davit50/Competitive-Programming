// __Davit__
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define rv(v) v.rbegin(),v.rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Davit cout.tie(NULL);

using namespace std;
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
const int INF = 1e9;


ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
//ll binpow(ll a, ll b, ll mod) {
//    a %= mod;
//    if (b == 0)return 1;
//    if (b & 1) return binpow(a, b / 2, mod) * binpow(a, b / 2, mod) * a;
//    return binpow(a, b / 2, mod) * binpow(a, b / 2, mod);
//}


int main() {
//    Code By Davit
    cout << binpow(2, 10, mod);
}













