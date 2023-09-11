#include<bits/stdc++.h>

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
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);

void __print(int x) { cerr << x; }

void __print(long x) { cerr << x; }

void __print(long long x) { cerr << x; }

void __print(unsigned x) { cerr << x; }

void __print(unsigned long x) { cerr << x; }

void __print(unsigned long long x) { cerr << x; }

void __print(float x) { cerr << x; }

void __print(double x) { cerr << x; }

void __print(long double x) { cerr << x; }

void __print(char x) { cerr << '\'' << x << '\''; }

void __print(const char *x) { cerr << '\"' << x << '\"'; }

void __print(const string &x) { cerr << '\"' << x << '\"'; }

void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int main() {
//    Code
//    By
//    Davit
    int t, n;
    cin >> t >> n;
    auto cyc_right = [&n](int x) -> int {
        x <<= 1;
        if (x & (1 << n)) x ^= (1 << n) ^ 1;
        return x;
    };
    auto str_to_bin = [&n](string s) -> int {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') res ^= (1 << i);
        }
        return res;
    };
    vector<int> rep(1 << n, -1);
    for (int i = 0; i < 1 << n; ++i) {
        int j = i;
        while (rep[j] == -1) {
            rep[j] = i;
            j = cyc_right(j);
        }
    }

    vector<vector<bool>> dp(3 * n + 1, vector<bool>(1 << n));
    dp[0][rep[0]] = 1;
    int move = 0;
    for (int i = 1; i <= n + n + n; i++) {
        move ^= (1 << ((i - 1) % n));
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[i - 1][rep[mask]])dp[i][rep[mask ^ move]] = 1;
        }
    }

    while (t--) {
        string x, y;
        cin >> x >> y;
        int fin = str_to_bin(x);
        int pad = str_to_bin(y);
        int cur = 0;
        for (int i = 0; i <= 3 * n; ++i) {
            if (dp[i][rep[cur ^ fin]]) {
                cout << i << "\n";
                break;
            }
            cur ^= pad;
            pad = cyc_right(pad);
        }
    }
    return 0;
}

