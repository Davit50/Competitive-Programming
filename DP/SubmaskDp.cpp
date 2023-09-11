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
using str = string;
const ll mod = 1e9 + 7;
const ll INF = 1e11;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


int main() {
    //time complexity is 3^n
    int n = 10;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {

        }
    }

}