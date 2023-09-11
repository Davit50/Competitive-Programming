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


ll MOD = 1000000007;

ll NO_OPERATION = LONG_LONG_MAX;
ll NEUTRAL_ELEMENT = 0;


struct node {
    ll operations, values;
};
vector<node> seg;
int n;
int sz = 1;


ll modify_op(ll a, ll b, ll len) {
    if (b == NO_OPERATION)return a;
    return b * len;
}

ll calc_op(ll a, ll b) {
    return a + b;
}

void propagate(int l, int r, int x) {
    if (l == r)return;
    if (seg[x].operations == NO_OPERATION)return;
    int m = (l + r) >> 1;
    seg[x + x + 1].operations = modify_op(seg[x + x + 1].operations, seg[x].operations, 1);
    seg[x + x + 2].operations = modify_op(seg[x + x + 2].operations, seg[x].operations, 1);
    seg[x + x + 1].values = modify_op(seg[x + x + 1].values, seg[x].operations, m - l + 1);
    seg[x + x + 2].values = modify_op(seg[x + x + 2].values, seg[x].operations, r - m);

    seg[x].operations = NO_OPERATION;
}


void modify(int l, int r, int x, int lx, int rx, int val) {
    propagate(l, r, x);
    if (l > rx || r < lx)return;
    if (lx <= l && r <= rx) {
        seg[x].operations = modify_op(seg[x].operations, val, 1);
        seg[x].values = modify_op(seg[x].values, val, r - l + 1);
        return;
    }

    int m = (l + r) >> 1;
    modify(l, m, x + x + 1, lx, rx, val);
    modify(m + 1, r, x + x + 2, lx, rx, val);
    seg[x].values = calc_op(seg[x + x + 1].values, seg[x + x + 2].values);

}

void modify(int l, int r, int val) {
    modify(0, sz - 1, 0, l, r, val);
}


ll calc(int l, int r, int x, int lx, int rx) {
    propagate(l, r, x);
    if (lx <= l && r <= rx)return seg[x].values;
    if (l > rx || r < lx)return NEUTRAL_ELEMENT;
    int m = (l + r) >> 1;
    ll a = calc(l, m, x + x + 1, lx, rx);
    ll b = calc(m + 1, r, x + x + 2, lx, rx);
    return calc_op(a, b);
}

ll calc(int l, int r) {
    return calc(0, sz - 1, 0, l, r);
}


int main() {
    int q;
    cin >> n >> q;
    while (sz < n)sz <<= 1;
    seg.resize(sz * 2, {0, 0});
//    build(0, sz - 1, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            modify(--l, --r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << calc(--l, --r) << "\n";
        }
    }
}
