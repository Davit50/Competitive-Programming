#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define FOR(i, n) for(int i=0;i<n;i++)
#define fast ios::sync_with_stdio(false);

using namespace std;
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);



const int MAXN = 1e5 + 5;

int n, q, a[MAXN], ans[MAXN], cnt[MAXN];

struct Query {
    int l, r, id;

    bool operator<(const Query &o) const {
        if (l / sqrt(n) != o.l / sqrt(n)) return l / sqrt(n) < o.l / sqrt(n);
        return r < o.r;
    }
};

void add(int i) {
    cnt[a[i]]++;
}

void remove(int i) {
    cnt[a[i]]--;
}

int main() {
    Query qs[MAXN];
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }

    sort(qs + 1, qs + q + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++) {
        while (l > qs[i].l) add(--l);
        while (r < qs[i].r) add(++r);
        while (l < qs[i].l) remove(l++);
        while (r > qs[i].r) remove(r--);
        ans[qs[i].id] = cnt[qs[i].r];
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
    return 0;
}

//https://www.spoj.com/problems/ZQUERY/