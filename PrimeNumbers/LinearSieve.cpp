// __Davit__
#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()

using namespace std;
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;

// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


int main() {

    vector<int> lp(N + 1);
    vector<int> pr;

    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }

    for (int i = 0; i < pr.size(); i++)cout << pr[i] << " ";
}

