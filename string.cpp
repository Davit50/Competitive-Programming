#include <bits/stdc++.h>

using namespace std;
using str = string;
using ll = long long;

#define pb push_back

vector<ll> z_function(string &s, ll len) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    vector<ll> ans;
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        if (z[i] == len) ans.push_back(i);
    }
    return ans;
}

vector<str> split(string a, string b) {
    string st = b + '$' + a;
    vector<ll> id = z_function(st, b.length());
    for (ll i = 0; i < id.size(); i++) id[i] = id[i] - b.length() - 1;
    vector<str> res;
    ll beg = 0;
    for (ll i = 0; i < id.size(); i++) {
        res.pb(a.substr(beg, id[i] - beg));
        beg = id[i] + 1;
    }
    res.pb(a.substr(beg, a.size()));
    return res;
}

str join(vector<str> v, str concat = " ") {
    str res = "";
    for (ll i = 0; i < v.size(); i++) {
        res += v[i];
        if (i != v.size() - 1)res += concat;
    }
    return res;
}


int main() {


}
