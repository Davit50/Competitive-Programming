#include <bits/stdc++.h>

using namespace std;
using vec = vector<int>;
using vvec = vector<vector<int>>;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gp(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    queue<int> q;
    vector<bool> vis(n);
    vector<int> dist(n, 0);
    q.push(0);
    vis.front() = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i: gp[cur]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }

    for (auto &i: dist)cout << i << endl;

}