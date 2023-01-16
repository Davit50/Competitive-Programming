#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 30 * 1e3 + 5;
vector<vector<int>> gp;
vector<bool> vis;

int n, m;

bool dfs(int u, int p = -1) {
    vis[u] = 1;
    for (auto &v: gp[u]) {
        if (p != v) {
            if (!vis[v]) {
                if (dfs(v, u)) return 1;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    gp = vector<vector<int>>(n);
    vis = vector<bool>(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gp[--u].push_back(--v);
        gp[v].push_back(u);
    }
    dfs(0);
}