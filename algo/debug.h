#include<bits/stdc++.h>

#define ll long long
using namespace std;

void __print(int x) { cerr << x; }

void __print(long x) { cerr << x; }

void __print(long long x) { cerr << x; }

void __print(unsigned x) { cerr << x; }

void __print(unsigned long x) { cerr << x; }

void __print(unsigned long long x) { cerr << x; }

void __print(float x) { cerr << x; }

void __print(double x) { cerr << x; }

void __print(long double x) { cerr << x; }

void __print(char x) { cerr << '\'' << x << '\''; }

void __print(const char *x) { cerr << '\"' << x << '\"'; }

void __print(const string &x) { cerr << '\"' << x << '\"'; }

void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

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

    void modify(int l, int r, int x, int index, int value) {
        if (l == r) {
            seg[x] = value;
            return;
        }
        int m = (l + r) / 2;
        if (m >= index) modify(l, m, x + x + 1, index, value);
        else modify(m + 1, r, x + x + 2, index, value);
        seg[x] = merge(seg[x + x + 1], seg[x + x + 2]);

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