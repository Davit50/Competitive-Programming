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

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

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
// using namespace __gnu_pbds;

// template<typename T, typename Compare = less<T>>
// using indexed_set = tree<
//         T,
//         null_type,
//         Compare,
//         rb_tree_tag,
//         tree_order_statistics_node_update>;

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
    vector<vector<int> > m_trie;
};

class LCA {
public:
    LCA(int n) {
        while ((1 << m_LOG) <= n)m_LOG++;
        m_gp = vector<vector<int> >(n);
        m_up = vector<vector<int> >(n, vector<int>(m_LOG));
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
    vector<vector<int> > m_gp;
    vector<vector<int> > m_up;
    vector<int> m_depth;
    int m_LOG = 1;
};

class DIJKSTRA {
public:
    DIJKSTRA(int n) : m_n(n) {
        m_gp = vector<vector<pair<int, long long> > >(n);
    }

    void addEdge(int u, int v, long long w) {
        m_gp[u].push_back({v, w});
    }

    vector<long long> getDist(int u) {
        vector<ll> p(m_n, -1), d(m_n, INF);

        set<pair<ll, ll> > q;
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
        return d;
    }

private:
    const long long INF = 1e18;
    int m_n;
    vector<vector<pair<int, long long> > > m_gp;
};

class SegmentTree {
    //m_modify_type : {assign, add}
    //m_query_type : {sum,min,max}

    // vector<long long> a = {1, 2, 3, 4, 5};
    // SegmentTree seg1(a.size(), "add", "sum");
    // seg1.build(a);
    // std::cout<<seg1.get(1, 3);
    // seg1.modify(1, 3, 10);

public:
    SegmentTree(int size, const string &modify_type, const string &query_type)
        : m_n(size), m_modify_type(modify_type), m_query_type(query_type) {
        m_seg.resize(4 * m_n);
        if (m_query_type == "sum") m_default_value = 0;
        else if (m_query_type == "min") m_default_value = LLONG_MAX;
        else if (m_query_type == "max") m_default_value = LLONG_MIN;
    }

    void build(const vector<long long> &arr) {
        build(0, 0, m_n - 1, arr);
    }

    void modify(int l, int r, long long val) {
        modify(0, 0, m_n - 1, l, r, val);
    }

    long long get(int l, int r) {
        return get(0, 0, m_n - 1, l, r);
    }

private:
    void build(int node, int l, int r, const vector<long long> &arr) {
        if (l == r) {
            m_seg[node].value = arr[l];
        } else {
            int m = (l + r) / 2;
            build(2 * node + 1, l, m, arr);
            build(2 * node + 2, m + 1, r, arr);
            m_seg[node].value = combine(m_seg[2 * node + 1].value, m_seg[2 * node + 2].value);
        }
    }

    void push(int node, int l, int r) {
        if (m_seg[node].has_assign) {
            m_seg[node].value = apply_assign(m_seg[node].lazy_assign, r - l + 1);
            if (l != r) {
                apply_assign_lazy(2 * node + 1, m_seg[node].lazy_assign);
                apply_assign_lazy(2 * node + 2, m_seg[node].lazy_assign);
            }
            m_seg[node].lazy_assign = 0;
            m_seg[node].lazy_add = 0;
            m_seg[node].has_assign = false;
        } else if (m_seg[node].lazy_add != 0) {
            m_seg[node].value = apply_add(m_seg[node].value, m_seg[node].lazy_add, r - l + 1);
            if (l != r) {
                m_seg[2 * node + 1].lazy_add += m_seg[node].lazy_add;
                m_seg[2 * node + 2].lazy_add += m_seg[node].lazy_add;
            }
            m_seg[node].lazy_add = 0;
        }
    }

    void apply_assign_lazy(int node, long long val) {
        m_seg[node].lazy_assign = val;
        m_seg[node].has_assign = true;
        m_seg[node].lazy_add = 0;
    }

    long long apply_add(long long current, long long val, int len) {
        if (m_query_type == "sum") return current + val * len;
        else return current + val;
    }

    long long apply_assign(long long val, int len) {
        if (m_query_type == "sum") return val * len;
        else return val;
    }

    long long combine(long long a, long long b) {
        if (m_query_type == "sum") return a + b;
        else if (m_query_type == "min") return min(a, b);
        else return max(a, b);
    }

    void modify(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            if (m_modify_type == "assign") {
                apply_assign_lazy(node, val);
            } else if (m_modify_type == "add") {
                m_seg[node].lazy_add += val;
            }
            push(node, l, r);
            return;
        }

        int m = (l + r) / 2;
        modify(2 * node + 1, l, m, ql, qr, val);
        modify(2 * node + 2, m + 1, r, ql, qr, val);
        m_seg[node].value = combine(m_seg[2 * node + 1].value, m_seg[2 * node + 2].value);
    }

    long long get(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return m_default_value;
        if (ql <= l && r <= qr) return m_seg[node].value;
        int m = (l + r) / 2;
        long long left = get(2 * node + 1, l, m, ql, qr);
        long long right = get(2 * node + 2, m + 1, r, ql, qr);
        return combine(left, right);
    }

private:
    struct Node {
        long long value = 0;
        long long lazy_add = 0;
        long long lazy_assign = 0;
        bool has_assign = false;
    };

    int m_n;
    vector<Node> m_seg;
    string m_modify_type, m_query_type;
    long long m_default_value;
};

void solve() {
}

int main() {
    int t = 1;
    //    cin >> t;
    while (t--)solve();
}
