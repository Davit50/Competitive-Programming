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
#include <random>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define ME cout.tie(NULL);

using namespace std;
using namespace __gnu_pbds;

//#include "Algo/debug.h"
template<typename T, typename Compare = less<T>>
using indexed_set = tree<
        T,
        null_type,
        Compare,
        rb_tree_tag,
        tree_order_statistics_node_update>;

//indexed_set<int> int_set;
//*int_set.find_by_order(1)
//int_set.order_of_key(1)
namespace RND {
    mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
    //mt19937 myrand(373);

    ll RANDOM(ll l, ll r) {
        ll res = myrand() % (r - l + 1) + l;
        return res;
    }

    void shuffle(vector<int> &a) {
        for (int i = 0; i < static_cast<int>(a.size()); i++) {
            int idx = RANDOM(0, i);
            swap(a[i], a[idx]);
        }
    }
};

class DSU {
public:
    DSU(int n) {
        m_parent.resize(n);
        m_size.resize(n);
        for (int i = 0; i < n; i++)m_size[i] = 1, m_parent[i] = i;
    }

    int get(int v) {
        return v == m_parent[v] ? v : (m_parent[v] = get(m_parent[v]));
    }

    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b) {
            if (m_size[a] < m_size[b]) swap(a, b);
            m_parent[b] = a;
            m_size[a] += m_size[b];
        }
    }

private:
    vector<int> m_parent, m_size;

};


class TRIE {
public:
    bool search(const string &word) {
        int node = 0;
        for (int i = 0; i < (int) word.size(); i++) {
            char c = word[i];
            if (m_trie[node][c - 'a'] == 0) return false;
            node = m_trie[node][c - 'a'];
        }
        return true;
    }


    void insert(const string &word) {
        int node = 0;
        for (char c: word) {
            if (m_trie[node][c - 'a'] == 0) {
                m_trie.push_back(vector<int>(26));
                m_trie[node][c - 'a'] = (int) m_trie.size() - 1;
            }
            node = m_trie[node][c - 'a'];
        }
    }

private:
    vector<vector<int>> m_trie;
};

class LCA {
public:
    LCA(int n) {
        while ((1 << m_LOG) <= n)m_LOG++;
        m_gp = vector<vector<int>>(n);
        m_up = vector<vector<int>>(n, vector<int>(m_LOG));
        m_depth = vector<int>(n);

        for (int i = 0; i < m_LOG; i++) m_up[0][i] = -1;

    }

    void run() {
        dfs(0);
    }

    int getKthParent(int u, int k) {
        for (int i = m_LOG - 1; i >= 0; i--) {
            if (k & (1 << i)) {
                u = m_up[u][i];
                if (u == -1)break;
            }
        }
        return u;

    }


    int lca(int a, int b) {
        if (m_depth[a] < m_depth[b])swap(a, b);
        int diff = m_depth[a] - m_depth[b];
        for (int i = m_LOG - 1; i >= 0; i--) {
            if (diff & (1 << i)) a = m_up[a][i];
        }
        if (a == b)return a;

        for (int i = m_LOG - 1; i >= 0; i--) {
            if (m_up[a][i] != m_up[b][i]) {
                a = m_up[a][i];
                b = m_up[b][i];
            }
        }
        return m_up[a][0];
    }

    void addEdge(int u, int v) {
        //u is parent of v
        m_gp[u].push_back(v);
    }

private:
    void dfs(int u) {
        for (auto v: m_gp[u]) {
            m_depth[v] = m_depth[u] + 1;
            m_up[v][0] = u;
            for (int i = 1; i < m_LOG; i++) {
                if (m_up[v][i - 1] == -1)m_up[v][i] = -1;
                else m_up[v][i] = m_up[m_up[v][i - 1]][i - 1];
            }
            dfs(v);
        }
    }

private:
    vector<vector<int>> m_gp;
    vector<vector<int>> m_up;
    vector<int> m_depth;
    int m_LOG = 1;

};

class DIJKSTRA {
public:
    DIJKSTRA(int n) : m_n(n) {
        m_gp = vector<vector<pair<int, long long>>>(n);
    }

    void addEdge(int u, int v, long long w) {
        m_gp[u].push_back({v, w});
    }

    vector<long long> getDist(int u) {
        vector<ll> p(m_n, -1), d(m_n, INF);

        set<pair<ll, ll>> q;
        q.insert({0, u});
        d[u] = 0;
        while (!q.empty()) {
            ll v = q.begin()->second;
            q.erase(q.begin());
            for (auto edge: m_gp[v]) {
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
//        ll t = m_n - 1;
//        vector<ll> path;
//        while (t != -1) {
//            path.push_back(t);
//            t = p[t];
//        }
//        reverse(path.begin(), path.end());
//        if (d[m_n - 1] == INF) {
//            cout << -1;
//            return 0;
//        }
//        for (ll i = 0; i < path.size(); i++) cout << path[i] + 1 << " ";
        return d;


    }


private:
    const long long INF = 1e18;
    int m_n;
    vector<vector<pair<int, long long>>> m_gp;

};

void solve() {

}

int main() {

    int t = 1;
//    cin >> t;
    while (t--)solve();
}

