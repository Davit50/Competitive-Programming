//Finding Negative cycle
//worst O(N*M)
//average O(M)

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
const int mod = 1e9 + 7;
const int INF = 1e8;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


vector<vector<pair<int, int>>> gp;

int main() {
    int n, m;
    cin >> n >> m;
    gp.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        gp[u].pb({v, w});
    }
    vector<int> d(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;
    //s is the starting vertex
    int s = 0;
    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;
        for (auto edge: gp[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n) {
                        cout << "negative cycle\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "OK\n";
}