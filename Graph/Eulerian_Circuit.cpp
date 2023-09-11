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
        tree_order_statistics_node_update> indexed_set;


//#include "algo/debug.h"



//we need to print the path to get from any vertex x to x using all the edges
//degree of each vertex should be even

int n, m;
vector<multiset<int>> gp;
vector<int> ans;

void dfs(int u) {
    while ((int) gp[u].size()) {
        int to = *gp[u].begin();
        gp[u].erase(gp[u].find(to));
        gp[to].erase(gp[to].find(u));
        dfs(to);
    }
    ans.pb(u);
}

int main() {
    cin >> n >> m;
    gp.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gp[u].insert(v);
        gp[v].insert(u);
    }
    for (int i = 0; i < n; i++) {
        if ((int) (gp[i].size()) & 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    dfs(0);
    if ((int) ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto x: ans)cout << x + 1 << " ";
}