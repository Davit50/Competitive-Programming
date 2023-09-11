#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define vr(v) v.begin(),v.end()
#define rv(v) v.rbegin(),v.rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Davit cout.tie(NULL);

using namespace std;
using str = string;
const ll mod = 1e9 + 7;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);
//    freopen("fire.in", "r", stdin);
//    freopen("fire.out", "w", stdout);

//mt19937 mt(time(nullptr));


vector<ll> bit;
int n;

ll sum(int r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
}

ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
}

int main() {
    int q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    bit.resize(n, 0);
    for (int i = 0; i < n; i++) add(i, v[i]);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            add(i, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sum(l, r) << "\n";
        }
    }
}

