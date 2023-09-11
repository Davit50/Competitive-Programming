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
//    freopen("cowmbat.in", "r", stdin);
//    freopen("cowmbat.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<vector<ll>> cost(m, vector<ll>(m));
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) { cin >> cost[i][j]; }


    for (int mid = 0; mid < m; mid++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cost[i][j] = min(cost[i][j], cost[i][mid] + cost[mid][j]);
            }
        }
    }


    vector<vector<ll>> v(n + 1, vector<ll>(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = cost[s[i - 1] - 'a'][j];
            v[i][j] += v[i - 1][j];
        }
    }

    auto f = [&](int letter, int l, int r) {
        ll res = v[r][letter];
        res -= v[l - 1][letter];
        return res;
    };
    vector<vector<ll>> dp(n + 1, vector<ll>(m, INF));
    vector<ll> mn(n + 1, INF);
    mn[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + f(j, i, i));
            if (i >= k) {
                dp[i][j] = min(dp[i][j], mn[i - k] + f(j, i - k + 1, i));
            }
            mn[i] = min(mn[i], dp[i][j]);
        }
    }
    cout << mn[n] << endl;

}