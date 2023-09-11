#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX;


int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> gp(n);
    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        gp[u].push_back({v, w});
        gp[v].push_back({u, w});
    }
    vector<ll> p(n, -1), d(n, INF);

    set<pair<ll, ll>> q;
    q.insert({0, 0});
    d[0] = 0;
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge: gp[v]) {
            ll to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
    ll t = n - 1;
    vector<ll> path;
    while (t != -1) {
        path.push_back(t);
        t = p[t];
    }
    reverse(path.begin(), path.end());
    if (d[n - 1] == INF) {
        cout << -1;
        return 0;
    }
    for (ll i = 0; i < path.size(); i++) cout << path[i] + 1 << " ";


}