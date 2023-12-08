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

//#include "algo/debug.h"
struct hatvac {
    multiset<int> stl, str;
    ll sml = 0, smr = 0;
    void balance() {
        if (stl.size() < str.size()) {
            int val = *str.begin();
            stl.insert(val);
            sml += val;
            str.erase(str.begin());
            smr -= val;
        }
        if (stl.size() > str.size() + 1) {
            int val = *prev(stl.end());
            str.insert(val);
            smr += val;
            stl.erase(prev(stl.end()));
            sml -= val;
        }
    }

    void add(int x) {
        if (stl.empty()) {
            stl.insert(x);
            sml += x;
            return;
        }
        if (x <= *prev(stl.end())) stl.insert(x), sml += x;
        else str.insert(x), smr += x;
        balance();
    }

    void rem(int x) {
        if (x <= *prev(stl.end())) stl.erase(stl.find(x)), sml -= x;
        else str.erase(str.find(x)), smr -= x;
        balance();
    }

    ll cost() {
        if (stl.empty()) return 0;
        ll med = *prev(stl.end());
        return (stl.size() * med - sml) + (smr - str.size() * med);
    }
};

int main() {

}
