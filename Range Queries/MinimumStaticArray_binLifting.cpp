#include<bits/stdc++.h>

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
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


//TIME COMPLEXITY
//Sparse Table O(NlogN)
//each query O(1)

vector<vector<pair<ll, ll>>> up;
ll LOG = 1;


int log(ll x) {
    return 64 - __builtin_clzll(x) - 1;
}

ll query(ll l, ll r) {
    ll k = (ll) log(r - l + 1);
    return min(up[l][k].ss, up[r - (1 << k) + 1][k].ss);
}


void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    while (1 << LOG < n)LOG++;
    LOG++;
    up = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll >>(LOG, {0, 2e9}));
    for (int i = 0; i < n; i++) {
        up[i][0].ff = i + 1;
        up[i][0].ss = v[i];
    }
    up[n - 1][0].ff = n - 1;
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            up[i][j].ss = min(up[i][j - 1].ss, up[up[i][j - 1].ff][j - 1].ss);
            up[i][j].ff = up[up[i][j - 1].ff][j - 1].ff;
        }
    }
//    for(int k = 1; k < LOG; k++) {
//        for(int i = 0; i + (1 << k) - 1 < n; i++) {
//            m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
//        }
//    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ll x = query(l, r);
        cout << x << endl;
    }

}

int main() {
//    Code By Davit
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}




