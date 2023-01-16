#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>


#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define vr(v) v.begin(),v.end()
#define rv(v) v.rbegin(),v.rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Davit cout.tie(NULL);

using namespace std;
using str = string;
const ll mod = 998244353;
const int inf = 1e9;
//cout << fixed<<setprecision(n);

// printf("%.9f\n", x);
//mt19937 mt(time(nullptr));



const int N = 200005;

ll c;
int h[N];
ll dp[N];
vector<pair<ll, ll>> mas;

//k1x+b1=k2x+b2 => x=(b2-b1)/(k1-k2)
long double calc(pair<ll, ll> p1, pair<ll, ll> p2) {
    return (long double) (p1.ss - p2.ss) / (long double) (p2.ff - p1.ff);
}

void add(ll k, ll b) {
    while ((int) mas.size() >= 2) {
        int sz = (int) mas.size();
        auto cur = make_pair(k, b);
        auto lst1 = mas[sz - 1];
        auto lst2 = mas[sz - 2];
        if (calc(cur, lst1) < calc(lst1, lst2)) {
            mas.pop_back();
        } else {
            break;
        }
    }
    mas.emplace_back(k, b);
}
//

int pointer = 0;

//ll get(int x) {
//    pointer = min(pointer, (int) mas.size() - 1);
//    while (pointer < mas.size() - 1) {
//        if (x < calc(mas[pointer], mas[pointer + 1])) {
//            break;
//        } else pointer++;
//    }
//    return mas[pointer].ff * 1ll * x + mas[pointer].ss;
//}
ll get(int x) {
    int l = 0, r = (int) mas.size() - 2, res = (int) mas.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        ///
        if (x < calc(mas[mid], mas[mid + 1])) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return mas[res].ff * 1ll * x + mas[res].ss;
}

int main() {
    int n;

    cin >> n >> c;
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    dp[0] = 0;
    add(-2ll * h[0], dp[0] + h[0] * 1ll * h[0]);

    for (int i = 1; i < n; i++) {
        dp[i] = get(h[i]) + c + h[i] * 1ll * h[i];
        add(-2ll * h[i], dp[i] + h[i] * 1ll * h[i]);
    }
//    dp[i] = dp[j] + h[i] * h[i] - 2 * h[i] * h[j] + h[j] * h[j] + c;

    cout << dp[n - 1] << endl;
    return 0;
}



