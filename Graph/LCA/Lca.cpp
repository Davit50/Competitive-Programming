

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
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);



vector<vector<int>> gp;
vector<int> parent, tin, tout, lvl;
int time0 = 0;

void dfs(int u, int p = -1) {
    tin[u] = time0++;
    lvl[u] = lvl[p] + 1;
    for (auto v: gp[u]) {
        if (v != p) {
            parent[v] = u;
            dfs(v, u);
        }
    }
    tout[u] = time0++;

}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main() {
    int n, q;
    cin >> n >> q;
    gp = vector<vector<int>>(n);
    lvl = tin = tout = parent = vector<int>(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gp[u].pb(v);
        gp[v].pb(u);
    }
    dfs(0);
//    cout << is_ancestor(0, 4);


}


