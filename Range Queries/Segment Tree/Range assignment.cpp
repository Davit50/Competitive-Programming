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
const ll mod = 1e9 + 7;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);
//    freopen("fire.in", "r", stdin);
//    freopen("fire.out", "w", stdout);

//mt19937 mt(time(nullptr));
//__builtin_clz(x): the number of zeros at the beginning of the number
//__builtin_ctz(x): the number of zeros at the end of the number
//__builtin_popcount(x): the number of 1s



vector<ll> seg;
int n;
int sz = 1;
ll NO_OPERATION = LLONG_MIN;

void propagate(int x, int lx, int rx) {
    if (seg[x] == NO_OPERATION)return;
    if (lx == rx)return;
    seg[2 * x + 1] = seg[x];
    seg[2 * x + 2] = seg[x];
    seg[x] = NO_OPERATION;
}

void modify(int l, int r, ll v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (lx > r || rx < l)return;
    if (lx >= l && rx <= r) {
        seg[x] = v;
        return;
    }
    int m = (lx + rx) / 2;
    modify(l, r, v, 2 * x + 1, lx, m);
    modify(l, r, v, 2 * x + 2, m + 1, rx);

}

void modify(int l, int r, int v) {
    modify(l, r, v, 0, 0, sz - 1);
}


ll get(int i, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (lx == rx) return seg[x];
    int m = (lx + rx) / 2;
    if (i <= m) {
        return get(i, 2 * x + 1, lx, m);
    } else {
        return get(i, 2 * x + 2, m + 1, rx);
    }
}

ll get(int i) {
    return get(i, 0, 0, sz - 1);
}

int main() {
    int q;
    cin >> n >> q;
    while (sz < n)sz <<= 1;
    seg.resize(sz * 2, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            modify(l, --r, v);
        } else {
            int i;
            cin >> i;
            cout << get(i) << "\n";
        }
    }
}
