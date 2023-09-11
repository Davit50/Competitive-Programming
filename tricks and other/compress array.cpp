#define _CRT_SECURE_NO_WARNINGS

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
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> mas;
    for (int i = 0; i < n; i++)cin >> v[i], mas.pb(v[i]);
    sort(vr(mas));
    mas.resize(unique(vr(mas)) - mas.begin());
    vector<int> compressed(n);
    for (int i = 0; i < n; i++) compressed[i] = lower_bound(vr(mas), v[i]) - mas.begin();
    for (int i = 0; i < n; i++) cout << compressed[i] << " ";


}