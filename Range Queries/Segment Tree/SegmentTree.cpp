#include<bits/stdc++.h>

#define ll long long

using namespace std;

vector<ll> seg;
vector<ll> v;
int n;
int sz = 1;


void modify(int l, int r, int x, int index, int value) {
    if (l == r) {
        seg[x] = value;
        return;
    }
    int m = (l + r) / 2;
    if (m >= index) modify(l, m, x + x + 1, index, value);
    else modify(m + 1, r, x + x + 2, index, value);
    seg[x] = seg[x + x + 1] + seg[x + x + 2];

}

void modify(int index, int value) {
    modify(0, sz - 1, 0, index, value);
}


ll get(int l, int r, int x, int lx, int rx) {
    if (l >= lx && r <= rx)return seg[x];
    if (l > rx || r < lx)return 0;
    int m = (l + r) >> 1;
    ll a = get(l, m, x + x + 1, lx, rx);
    ll b = get(m + 1, r, x + x + 2, lx, rx);
    return a + b;
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
    seg[x] = seg[x + x + 1] + seg[x + x + 2];

}


int main() {
    int q;
    cin >> n >> q;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    while (sz < n)sz <<= 1;
    seg.resize(sz + sz);
    build(0, sz - 1, 0);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            modify(l, r);
        } else cout << get(l, r) << "\n";
    }
}

