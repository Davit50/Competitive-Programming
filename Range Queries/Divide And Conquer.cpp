#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define vr(v) v.begin(),v.end()
#define rv(v) v.rbegin(),v.rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Davit cout.tie(NULL);

using namespace std;
const ll mod = 1000000007;
const int inf = 1e9;
//cout << fixed<<setprecision(n);

//printf("%.9f\n", x);
//mt19937 mt(time(nullptr));


//#include "algo/debug.h"

const int N = 200005;
int left_[N], right_[N];
int n, q;

vector<int> ans;
vector<pair<int, int>> queries;
vector<int> v;


void solve(int l, int r, vector<int> idx) {
    if (idx.empty())return;
    if (l == r) {
        for (int i = 0; i < (int) idx.size(); i++) ans[idx[i]] = v[l];
        return;
    }
    int m = (l + r) >> 1;
    left_[m] = v[m];
    for (int i = m - 1; i >= l; i--) left_[i] = min(left_[i + 1], v[i]);
    right_[m] = v[m];
    for (int i = m + 1; i <= r; i++) right_[i] = min(right_[i - 1], v[i]);

    vector<int> todo[2];
    for (int i = 0; i < (int) idx.size(); i++) {
        int L = queries[idx[i]].ff;
        int R = queries[idx[i]].ss;
        if (L <= m && m < R) {
            ans[idx[i]] = min(left_[L], right_[R]);
            continue;
        }
        todo[L > m].pb(idx[i]);
    }
    solve(l, m, todo[0]);
    solve(m + 1, r, todo[1]);

}


int main() {
    cin >> n >> q;
    v = vector<int>(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    ans.resize(q);
    queries = vector<pair<int, int>>(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].ff >> queries[i].ss;
        queries[i].ff--;
        queries[i].ss--;
    }
    vector<int> idx(q);
    for (int i = 0; i < q; i++) idx[i] = i;
    solve(0, n - 1, idx);
    for (int i = 0; i < q; i++) cout << ans[i] << endl;

}