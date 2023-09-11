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
const ll MOD = 1000000007;


ll c2zi6(ll a, ll b) {
    if (b == 0) return 0;
    if (b & 1) return (2 * c2zi6(a, b / 2) + a) % MOD;
    return 2 * c2zi6(a, b / 2) % MOD;
}


int main() {
    cout << c2zi6(190890890464578764, 100890878964578764);//810617909
}



