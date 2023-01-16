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

//mt19937 mt(time(nullptr));
//__builtin_clz(x): the number of zeros at the beginning of the number
//__builtin_ctz(x): the number of zeros at the end of the number
//__builtin_popcount(x): the number of 1s
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


template<typename T, typename U>
static inline void mx(T &x, U y) {
    if (x < y) x = y;
}

template<typename T, typename U>
static inline void mn(T &x, U y) {
    if (x > y) x = y;
}

void solve() {

}

int main() {
//    Code By Davit
    int t = 1;
    cin >> t;
    while (t--)solve();


}

