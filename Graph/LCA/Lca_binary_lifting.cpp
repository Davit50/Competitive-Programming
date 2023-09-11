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
#define FOR(i, n) for(int i = 0;i<n;i++)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;


//#include "algo/debug.h"



vector<vector<int>> gp;

vector<int> depth;
vector<vector<int>> up;
int LOG = 1;


void dfs(int u) {
    for (auto v: gp[u]) {
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int i = 1; i < LOG; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        dfs(v);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b])swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = LOG - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
            a = up[a][i];
        }
    }
    if (a == b)return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    int n, q;
    cin >> n >> q;
    while ((1 << LOG) <= n)LOG++;
    depth.resize(n);
    gp.resize(n);
    up = vector<vector<int>>(n, vector<int>(LOG));
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        gp[x].pb(i);
    }
    up[0][0] = 0;
    dfs(0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u - 1, v - 1) + 1 << endl;
    }
}

