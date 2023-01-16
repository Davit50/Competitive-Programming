#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <stack>
#include <cstdio>
#include <climits>
#include <tuple>
#include <ctime>
#include <cstring>
#include <numeric>
#include <functional>
#include <chrono>
#include <cassert>
#include <bitset>
#include <fstream>

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
const int N = 2e5 + 5;
const int INF = 1e9;

// printf("%.9f\n", x);
// cout << fixed<<setprecision(n);





int n, m;
vector<vector<int>> gp;
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u: gp[v]) {
        if (!visited[u]) dfs(u);
    }
    ans.pb(v);
}

void top_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs(i);
    }
    reverse(vr(ans));

}

int main() {
    cin >> n >> m;
    gp.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        gp[--u].pb(--v);
    }
    top_sort();
    for (int i = 0; i < n; i++)cout << ans[i];
}