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
const ll INF = 1e18;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    vector<vector<ll>> p(n, vector<ll>(n, -1));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if (w < d[u][v]) d[u][v] = d[v][u] = w;
    }
    for (int i = 0; i < n; i++) d[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
//                if (d[i][k] + d[k][j] < d[i][j] - EPS) { for float numbers to prevent errors
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }

}

