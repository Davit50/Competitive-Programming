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
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Davit cout.tie(NULL);

using namespace std;
using str = string;
const ll mod = 1e9 + 7;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);
const int MAX_N = 10000;
const int LOG = 14;
vector<int> gp[MAX_N];
int up[MAX_N][LOG];
int depth[MAX_N];

void dfs(int u) {
    for (auto x: gp[u]) {
        depth[x] = depth[u] + 1;
        up[x][0] = u;
        for (int i = 1; i < LOG; i++) {
            up[x][i] = up[up[x][i - 1]][i - 1];
        }
        dfs(x);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b])swap(a, b);
    int k = (depth[a] - depth[b]);
    for (int i = LOG - 1; i >= 0; i--) {
        if (k & (1 << i)) a = up[a][i];

    }
    if (a == b) {
        return a;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        gp[u].pb(v);
    }
    dfs(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }


}