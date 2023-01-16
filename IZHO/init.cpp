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
using str = string;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);
//    freopen("fire.in", "r", stdin);
//    freopen("fire.out", "w", stdout);

//mt19937 mt(time(nullptr));
ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return ((a * b) / gcd(a, b)); }

bool isPrime(ll n) {
    if (n <= 1)return false;
    if (n <= 3)return true;
    if (n % 2 == 0 || n % 3 == 0)return false;
    for (ll i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;
    return true;
}


ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

//ALGO

//CONVEX HULL trick
//vector<pair<ll, ll>> mas;long double calc(pair<ll, ll> p1, pair<ll, ll> p2) {return (long double) (p1.ss - p2.ss) / (long double) (p2.ff - p1.ff);}void add(ll k, ll b) {while ((int) mas.size() >= 2) {     int sz = (int) mas.size();     auto cur = make_pair(k, b);     auto lst1 = mas[sz - 1];     auto lst2 = mas[sz - 2];     if (calc(cur, lst1) < calc(lst1, lst2)) {     mas.pop_back(); } else {     break; } } mas.emplace_back(k, b);}ll get(int x) {int l = 0, r = (int) mas.size() - 2, res = (int) mas.size() - 1;while (l <= r) {     int mid = (l + r) / 2;     if (x < calc(mas[mid], mas[mid + 1])) {     res = mid;     r = mid - 1; } else l = mid + 1; } return mas[res].ff * 1ll * x + mas[res].ss;}

//Lca
//vector<vector<int>> gp;vector<int> parent, tin, tout, lvl;int time0 = 0;void dfs(int u, int p = -1) {tin[u] = time0++;lvl[u] = lvl[p] + 1;for (auto v: gp[u]) {     if (v != p) {     parent[v] = u;     dfs(v, u); } } tout[u] = time0++;}bool is_ancestor(int u, int v) {return tin[u] <= tin[v] && tout[u] >= tout[v];}int main() {int n, q;cin >> n >> q;gp = vector<vector<int>>(n);lvl = tin = tout = parent = vector<int>(n, 0);for (int i = 0; i < n - 1; i++) {     int u, v;     cin >> u >> v;     u--, v--;     gp[u].pb(v);     gp[v].pb(u); } dfs(0);cout << is_ancestor(0, 4);}

//Lca bin_lifting
//const int MAX_N = 10000;const int LOG = 14;vector<int> gp[MAX_N];int up[MAX_N][LOG];int depth[MAX_N];void dfs(int u) {for (auto x: gp[u]) {     depth[x] = depth[u] + 1;     up[x][0] = u;     for (int i = 1; i < LOG; i++) {     up[x][i] = up[up[x][i - 1]][i - 1]; } dfs(x); }}int lca(int a, int b) {if (depth[a] < depth[b])swap(a, b);int k = (depth[a] - depth[b]);for (int i = LOG - 1; i >= 0; i--) {     if (k & (1 << i)) a = up[a][i]; } if (a == b) {     return a; } for (int i = LOG - 1; i >= 0; i--) {     if (up[a][i] != up[b][i]) {     a = up[a][i];     b = up[b][i]; } } return up[a][0];}int main() {int n;cin >> n;for (int i = 0; i < n - 1; i++) {     int u, v;     cin >> u >> v;     gp[u].pb(v); } dfs(0);int q;cin >> q;for (int i = 0; i < q; i++) {     int a, b;     cin >> a >> b;     cout << lca(a, b) << "\n"; }}

//Bfs
//int main() {int n, m;cin >> n >> m;vector<vector<int>> gp(n);while (m--) {     int u, v;     cin >> u >> v;     u--, v--;     gp[u].push_back(v);     gp[v].push_back(u); } queue<int> q;vector<bool> vis(n);vector<int> dist(n, 0);q.push(0);vis.front() = 1;while (!q.empty()) {     int cur = q.front();     q.pop();     for (auto &i: gp[cur]) {     if (!vis[i]) {     vis[i] = 1;     dist[i] = dist[cur] + 1;     q.push(i); } } } for (auto &i: dist)cout << i << endl;}

//Dijkstra
//int main() {ll n, m;cin >> n >> m;vector<vector<pair<ll, ll>>> gp(n);while (m--) {     ll u, v, w;     cin >> u >> v >> w;     --u, --v;     gp[u].push_back({v, w});     gp[v].push_back({u, w}); } vector<ll> p(n, -1), d(n, INF);set<pair<ll, ll>> q;q.insert({0, 0});d[0] = 0;while (!q.empty()) {     ll v = q.begin()->second;     q.erase(q.begin());     for (auto edge: gp[v]) {     ll to = edge.first;     ll len = edge.second;     if (d[v] + len < d[to]) {     q.erase({d[to], to});     d[to] = d[v] + len;     p[to] = v;     q.insert({d[to], to}); } } } ll t = n - 1;vector<ll> path;while (t != -1) {     path.push_back(t);     t = p[t]; } reverse(path.begin(), path.end());if (d[n - 1] == INF) {     cout << -1;     return 0; } for (ll i = 0; i < path.size(); i++) cout << path[i] + 1 << " ";}

//topological sort
//int n, m;vector<vector<int>> gp;vector<bool> visited;vector<int> ans;void dfs(int v) {visited[v] = true;for (int u: gp[v]) {     if (!visited[u]) dfs(u); } ans.pb(v);}void top_sort() {visited.assign(n, false);ans.clear();for (int i = 0; i < n; ++i) {     if (!visited[i]) dfs(i); } reverse(vr(ans));}int main() {cin >> n >> m;gp.resize(n);while (m--) {     int u, v;     cin >> u >> v;     gp[--u].pb(--v); } top_sort();for (int i = 0; i < n; i++)cout << ans[i];}

//Detect cycle
//int n, m;vector<int> col;vector<vector<int>> gp;bool dfs(int u) {col[u] = 1;for (int &v: gp[u]) {     if (col[v] == 0 && dfs(v)) return 1;     else if (col[v] == 1) return 1; } col[u] = 2;return 0;}int main() {cin >> n >> m;col = vector<int>(n);gp = vector<vector<int>>(n);for (int i = 0; i < m; i++) {     int u, v;     cin >> u >> v;     gp[--u].push_back(--v); } for (int i = 0; i < n; i++) {     if (col[i] == 0 && dfs(i)) {     cout << "Cycle";     return 0; } } cout << "Acyclic";}

//DSU
//vector<int> parent, sz;int find_set(int v) {return v == parent[v] ? v : (parent[v] = find_set(parent[v]));}void union_sets(int a, int b) {a = find_set(a);b = find_set(b);if (a != b) {     if (sz[a] < sz[b]) swap(a, b);     parent[b] = a;     sz[a] += sz[b]; }}int main() {ios_base::sync_with_stdio(false);cin.tie(NULL);int n, m;cin >> n >> m;parent.resize(n);sz.resize(n);for (int i = 0; i < n; i++)sz[i] = 1, parent[i] = i;while (m--) {     int u, v;     cin >> u >> v;     u--, v--;     union_sets(u, v); }}

//Erato sieve
//vector<bool> sieve(ll n) {vector<bool> v(n + 1, true);v[0] = v[1] = false;for (ll i = 2; i * i <= n; i++) {     if (v[i]) {     for (ll j = i * i; j <= n; j += i) v[j] = false; } } return v;}

//Linear Sieve
//int main() {vector<int> lp(N + 1);vector<int> pr;for (int i = 2; i <= N; ++i) {     if (lp[i] == 0) {     lp[i] = i;     pr.push_back(i); } for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {     lp[i * pr[j]] = pr[j]; } } for (int i = 0; i < pr.size(); i++)cout << pr[i] << " ";}

//Static Array Minimum (bin lift)
//vector<vector<pair<ll, ll>>> up;ll LOG = 1;int log(ll x) {return 64 - __builtin_clzll(x) - 1;}ll query(ll l, ll r) {ll k = (ll) log(r - l + 1);return min(up[l][k].ss, up[r - (1 << k) + 1][k].ss);}void solve() {ll n, q;cin >> n >> q;vector<ll> v(n);for (int i = 0; i < n; i++)cin >> v[i];while (1 << LOG < n)LOG++;LOG++;up = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll >>(LOG, {0, 2e9}));for (int i = 0; i < n; i++) {     up[i][0].ff = i + 1;     up[i][0].ss = v[i]; } up[n - 1][0].ff = n - 1;for (int j = 1; j < LOG; j++) {     for (int i = 0; i + (1 << j) - 1 < n; i++) {     up[i][j].ss = min(up[i][j - 1].ss, up[up[i][j - 1].ff][j - 1].ss);     up[i][j].ff = up[up[i][j - 1].ff][j - 1].ff; } } while (q--) {     ll l, r;     cin >> l >> r;     l--, r--;     ll x = query(l, r);     cout << x << endl; }}

//Segment Tree
//vector<int> v;vector<int> seg;int n;int sz = 1;void build(int l, int r, int x) {if (r == l) {     if (l < n) seg[x] = v[l];     return; } int m = (l + r) / 2;build(l, m, 2 * x + 1);build(m + 1, r, 2 * x + 2);seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);}int get(int l, int r, int lx, int rx, int x) {if (lx >= l && rx <= r)return seg[x];if (lx > r || rx < l)return INF;int m = (lx + rx) / 2;return min(get(l, r, lx, m, 2 * x + 1), get(l, r, m + 1, rx, 2 * x + 2));}int get(int l, int r) {return get(l, r, 0, sz - 1, 0);}void modify(int l, int r, int cur, int idx, int x) {if (l == r) {     seg[cur] = x;     return; } int m = (l + r) / 2;if (idx <= m)modify(l, m, 2 * cur + 1, idx, x);else modify(m + 1, r, 2 * cur + 2, idx, x);seg[cur] = min(seg[2 * cur + 1], seg[2 * cur + 2]);}void modify(int idx, int x) {modify(0, sz - 1, 0, idx, x);}int main() {int q;cin >> n >> q;while (sz < n)sz <<= 1;seg.resize(sz * 2, 0);v.resize(n);for (int i = 0; i < n; i++)cin >> v[i];build(0, sz - 1, 0);while (q--) {     int a, b, c;     cin >> a >> b >> c;     if (a == 1) modify(b, c);     else cout << get(b, c - 1) << "\n"; }}

//Fenwick Tree
//vector<ll> bit;int n;ll sum(int r) {ll ret = 0;for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];return ret;}ll sum(int l, int r) {return sum(r) - sum(l - 1);}void add(int idx, int delta) {for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;}int main() {int q;cin >> n >> q;vector<ll> v(n);for (int i = 0; i < n; i++)cin >> v[i];bit.resize(n, 0);for (int i = 0; i < n; i++) add(i, v[i]);while (q--) {     int type;     cin >> type;     if (type == 1) {     int i, x;     cin >> i >> x;     i--;     add(i, x); } else {     int l, r;     cin >> l >> r;     l--, r--;     cout << sum(l, r) << "\n"; } }}

//Segment Tree (maximum subarray sum)
//struct node {ll seg, pref, suf, sum;};vector<ll> v;vector<node> tree;int n, sz = 1;const node ZERO = {0, 0, 0, 0};node combine(node a, node b) {return {     max({a.seg, b.seg, a.suf + b.pref}),         max(a.pref, a.sum + b.pref),         max(b.suf, b.sum + a.suf),         a.sum + b.sum };}node one_element(int x) {return {     max(x, 0),         max(x, 0),         max(x, 0),         x };}void build(int l, int r, int x) {if (r == l) {     if (l < n) tree[x] = one_element(v[l]);     return; } int m = (l + r) / 2;build(l, m, 2 * x + 1);build(m + 1, r, 2 * x + 2);tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);}node get(int l, int r, int lx, int rx, int x) {if (lx >= l && rx <= r)return tree[x];if (lx > r || rx < l)return ZERO;int m = (lx + rx) / 2;return combine(get(l, r, m + 1, rx, 2 * x + 2), get(l, r, lx, m, 2 * x + 1));}node get(int l, int r) {return get(l, r, 0, sz - 1, 0);}void modify(int l, int r, int cur, int idx, int x) {if (l == r) {     tree[cur] = one_element(x);     return; } int m = (l + r) / 2;if (idx <= m)modify(l, m, 2 * cur + 1, idx, x);else modify(m + 1, r, 2 * cur + 2, idx, x);tree[cur] = combine(tree[2 * cur + 1], tree[2 * cur + 2]);}void modify(int idx, int x) {modify(0, sz - 1, 0, idx, x);}int main() {int q;cin >> n >> q;while (sz < n)sz <<= 1;tree.resize(sz * 2, ZERO);v.resize(n);for (int i = 0; i < n; i++)cin >> v[i];build(0, sz - 1, 0);cout << tree[0].seg << "\n";while (q--) {     int i, x;     cin >> i >> x;     modify(i, x);     cout << tree[0].seg << "\n"; }}

//binary convert
//string bit2to10(string bit2) {int bit10 = 0;while (bit2[0] == '0') bit2 = bit2.substr(1, bit2.size() - 1);for (int i = 0; i < bit2.size(); i++) {if (bit2[bit2.size() - 1 - i] == '1') {bit10 += pow(2, i);}}return to_string(bit10);}
//string bit2to8(string bit2) {string concat = "";string bit8 = "";while (bit2[0] == '0') bit2 = bit2.substr(1, bit2.size() - 1);if (bit2.size() % 3 == 1) bit2 = "00" + bit2;if (bit2.size() % 3 == 2) bit2 = '0' + bit2;for (int i = 0; i < (bit2.size() / 3); i++) {if (bit2.substr(i * 3, 3) == "000")concat = '0';if (bit2.substr(i * 3, 3) == "001")concat = '1';if (bit2.substr(i * 3, 3) == "010")concat = '2';if (bit2.substr(i * 3, 3) == "011")concat = '3';if (bit2.substr(i * 3, 3) == "100")concat = '4';if (bit2.substr(i * 3, 3) == "101")concat = '5';if (bit2.substr(i * 3, 3) == "110")concat = '6';if (bit2.substr(i * 3, 3) == "111")concat = '7';bit8 += concat;}return bit8;}
//string bit2to16(string bit2) {string bit16 = "";string concat;if (bit2.size() % 4 == 1)bit2 = "000" + bit2;if (bit2.size() % 4 == 2)bit2 = "00" + bit2;if (bit2.size() % 4 == 3)bit2 = '0' + bit2;for (int i = 0; i < (bit2.size() / 4); i++) {if (bit2.substr(4 * i, 4) == "0000")concat = '0';if (bit2.substr(4 * i, 4) == "0001")concat = '1';if (bit2.substr(4 * i, 4) == "0010")concat = '2';if (bit2.substr(4 * i, 4) == "0011")concat = '3';if (bit2.substr(4 * i, 4) == "0100")concat = '4';if (bit2.substr(4 * i, 4) == "0101")concat = '5';if (bit2.substr(4 * i, 4) == "0110")concat = '6';if (bit2.substr(4 * i, 4) == "0111")concat = '7';if (bit2.substr(4 * i, 4) == "1000")concat = '8';if (bit2.substr(4 * i, 4) == "1001")concat = '9';if (bit2.substr(4 * i, 4) == "1010")concat = 'A';if (bit2.substr(4 * i, 4) == "1011")concat = 'B';if (bit2.substr(4 * i, 4) == "1100")concat = 'C';if (bit2.substr(4 * i, 4) == "1101")concat = 'D';if (bit2.substr(4 * i, 4) == "1110")concat = 'E';if (bit2.substr(4 * i, 4) == "1111")concat = 'F';bit16 += concat;}return bit16;}
//string bit10to2(string bit10str) {string bit2 = "";ll bit10 = stoll(bit10str);if (bit10 == 0)return "0";while (bit10 != 1) {bit10 % 2 == 0 ? bit2 += "0" : bit2 += "1";bit10 /= 2;}bit2 += "1";reverse(bit2.begin(), bit2.end());return bit2;}
//string bit8to2(string bit8) {string bit2 = "";string concat = "";for (int i = 0; i < bit8.size(); i++) {if (bit8[i] == '0')concat = "000";if (bit8[i] == '1')concat = "001";if (bit8[i] == '2')concat = "010";if (bit8[i] == '3')concat = "011";if (bit8[i] == '4')concat = "100";if (bit8[i] == '5')concat = "101";if (bit8[i] == '6')concat = "110";if (bit8[i] == '7')concat = "111";bit2 += concat;}return bit2;}
//string bit16to2(string bit16) {string concat;string bit2 = "";for (int i = 0; i < bit16.size(); i++) {if (bit16[i] == '0')concat = "0000";if (bit16[i] == '1')concat = "0001";if (bit16[i] == '2')concat = "0010";if (bit16[i] == '3')concat = "0011";if (bit16[i] == '4')concat = "0100";if (bit16[i] == '5')concat = "0101";if (bit16[i] == '6')concat = "0110";if (bit16[i] == '7')concat = "0111";if (bit16[i] == '8')concat = "1000";if (bit16[i] == '9')concat = "1001";if (bit16[i] == 'A')concat = "1010";if (bit16[i] == 'B')concat = "1011";if (bit16[i] == 'C')concat = "1100";if (bit16[i] == 'D')concat = "1101";if (bit16[i] == 'E')concat = "1110";if (bit16[i] == 'F')concat = "1111";bit2 += concat;}return bit2;}

//combinatorica
//ll mul(ll a, ll b, ll res = 1) {if (a == b)return res;return (mul(a + 1, b, res * (a + 1)));}ll combenatorica(ll a, ll b) {return mul(b - a, b) / mul(1, a);}

//do {
//} while (next_permutation(permutation.begin(),permutation.end()));

//mask and submask 3^N
//for (int mask = 0; mask < (1 << n); mask++) {for (int submask = mask; submask; submask = (submask - 1) & mask){}}


//Sum of minimum elements of all subarrays
//  int main() {int n;cin >> n;vector<ll> p(n);for (int i = 0; i < n; i++)cin >> p[i];vector<pair<ll, ll>> borders(n);stack<int> st;st.push(0);borders[0].ff = 0;for (int i = 1; i < n; i++) {while (st.size() && p[st.top()] > p[i]) st.pop();if (st.empty())borders[i].ff = 0;else borders[i].ff = st.top() + 1;st.push(i);}borders[n - 1].ss = n - 1;st = stack<int>();st.push(n - 1);for (int i = n - 2; i >= 0; i--) {while (st.size() && p[st.top()] > p[i])st.pop();if (st.empty())borders[i].ss = n - 1;else borders[i].ss = st.top() - 1;st.push(i);}ll res = 0;for (int i = 0; i < n; i++) res += ((abs(i - borders[i].ff) + 1) * (abs(i - borders[i].ss) + 1)) * p[i];}

//Mo's algo
//const int MAXN = 1e5 + 5;int n, q, a[MAXN], ans[MAXN], cnt[MAXN];struct Query {int l, r, id;bool operator<(const Query &o) const {     if (l / sqrt(n) != o.l / sqrt(n)) return l / sqrt(n) < o.l / sqrt(n);     return r < o.r; }} qs[MAXN];void add(int i) {cnt[a[i]]++;}void remove(int i) {cnt[a[i]]--;}int main() {cin >> n >> q;for (int i = 1; i <= n; i++) cin >> a[i];for (int i = 1; i <= q; i++) {     cin >> qs[i].l >> qs[i].r;     qs[i].id = i; } sort(qs + 1, qs + q + 1);int l = 1, r = 0;for (int i = 1; i <= q; i++) {     while (l > qs[i].l) add(--l);     while (r < qs[i].r) add(++r);     while (l < qs[i].l) remove(l++);     while (r > qs[i].r) remove(r--);     ans[qs[i].id] = cnt[qs[i].r]; } for (int i = 1; i <= q; i++) cout << ans[i] << endl;return 0;}

int main() {


}