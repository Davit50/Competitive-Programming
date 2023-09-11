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

using namespace std;
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


vector<int> parent, sz;

int get(int v) {
    return v == parent[v] ? v : (parent[v] = find_set(parent[v]));
//    if (v == parent[v]) return v;
//    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++)sz[i] = 1, parent[i] = i;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        union_sets(u, v);
    }
}
