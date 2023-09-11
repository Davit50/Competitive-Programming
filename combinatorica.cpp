#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
vector<ll> fact, invfact;

ll count(int n, int k) {
    return (fact[n] * invfact[k] % mod * invfact[n - k] % mod);
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    fact.resize(n + 2);
    invfact.resize(n + 2);
    fact[0] = 1, invfact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    invfact[n] = binpow(fact[n], mod - 2, mod) % mod;
    for (int i = n; i >= 1; i--)invfact[i - 1] = (invfact[i] * i) % mod;
//    for (int i = 1; i <= n; i++) invfact[i] = binpow(fact[i], mod - 2, mod) % mod;
// -> ------------
    cout << count(5, 3);
}