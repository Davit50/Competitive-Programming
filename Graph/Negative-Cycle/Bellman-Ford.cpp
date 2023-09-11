//Bellman–Ford
//Finding Negative Cycle

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


struct node {
    int a, b, cost;
};

bool operator<(const node &a, const node &b) {
    return tie(a) < tie(b);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }
    // v is the starting node
    int v = 5;
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < m; ++j) {
            if (d[edges[j].a] < INF) {
                if (d[edges[j].b] > d[edges[j].a] + edges[j].cost) {
                    d[edges[j].b] = max(-INF, d[edges[j].a] + edges[j].cost);
                    p[edges[j].b] = edges[j].a;
                    x = edges[j].b;
                }
            }
        }
    }

    if (x == -1) cout << "No negative cycle from " << v;
    else {
        int y = x;
        for (int i = 0; i < n; ++i) y = p[y];
        vector<int> path;
        for (int cur = y;; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1) break;
        }
        reverse(path.begin(), path.end());
        cout << "Negative cycle: ";
        for (size_t i = 0; i < path.size(); ++i) cout << path[i] << ' ';
    }
//    for (int i = 0; i < n; i++)cout << d[i] << " ";

}