#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<bool> sieve(ll n) {
    vector<bool> v(n + 1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            for (ll j = i + i; j <= n; j += i) v[j] = false;
        }
    }
    return v;
}


int main() {
    vector<bool> a = sieve(20);
    for (int i = 0; i < a.size(); i++) {
        cout << i << " " << a[i] << endl;
    }

}

