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

//#include "algo/debug.h"
struct SegmentTree {
    vector<ll> seg;
    vector<ll> v;
    int n;
    int sz = 1;

    void __init__() {
        while (sz < n)sz <<= 1;
        seg.resize(sz + sz);
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void modify(int l, int r, int x, int index, ll value) {
        if (l == r) {
            seg[x] = value;
            return;
        }
        int m = (l + r) / 2;
        if (m >= index) modify(l, m, x + x + 1, index, value);
        else modify(m + 1, r, x + x + 2, index, value);
        seg[x] = merge(seg[x + x + 1], seg[x + x + 2]);

    }

    void modify(int index, ll value) {
        modify(0, sz - 1, 0, index, value);
    }


    ll get(int l, int r, int x, int lx, int rx) {
        if (l >= lx && r <= rx)return seg[x];
        if (l > rx || r < lx)return 0;
        int m = (l + r) >> 1;
        ll a = get(l, m, x + x + 1, lx, rx);
        ll b = get(m + 1, r, x + x + 2, lx, rx);
        return merge(a, b);
    }

    ll get(int l, int r) {
        return get(0, sz - 1, 0, l, r);
    }

    void build(int l, int r, int x) {
        if (l == r) {
            if (l < n)seg[x] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, x + x + 1);
        build(m + 1, r, x + x + 2);
        seg[x] = merge(seg[x + x + 1], seg[x + x + 2]);
    }
};
//

vector<vector<int>> gp;
int timer = 0;
vector<int> tin, tout;

void euler_tour(int u, int p) {
    tin[u] = timer++;
    for (auto x: gp[u]) {
        if (x == p)continue;
        euler_tour(x, u);
    }
    tout[u] = timer - 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> val(n);
    gp.resize(n);
    tin.resize(n);
    tout.resize(n);
    for (int i = 0; i < n; i++)cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gp[u].pb(v);
        gp[v].pb(u);
    }

    SegmentTree tree;
    tree.n = n;
    tree.__init__();

    euler_tour(0, -1);
    for (int i = 0; i < n; i++) tree.modify(tin[i], val[i]);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int node, new_val;
            cin >> node >> new_val;
            node--;
            tree.modify(tin[node], new_val);
        } else {
            int node;
            cin >> node;
            node--;
            cout << tree.get(tin[node], tout[node]) << endl;
        }
    }
}

