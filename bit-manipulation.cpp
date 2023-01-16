#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()

using namespace std;
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 998244353;
const int N = 2e5 + 5;
const int INF = 2e9;

// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)cin >> v[i];
    for (ll i = 0; i < (1 << n); i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) sum += v[j];
        }
        cout << sum << " ";
    }
}


int main() {
    int t = 1;
//    cin >> t;
    while (t--)solve();
}



