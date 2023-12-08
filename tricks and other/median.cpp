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


multiset<ll> left_, right_;
ll sumL = 0, sumR = 0;

void balance() {
    if (right_.size() > left_.size()) {
        sumL += *right_.begin();
        sumR -= *right_.begin();
        left_.insert(*right_.begin());
        right_.erase(right_.begin());
    }
    if (left_.size() > right_.size() + 1) {
        sumL -= *left_.rbegin();
        sumR += *left_.rbegin();
        right_.insert(*left_.rbegin());
        left_.erase(prev(left_.end()));
    }
}

void add(ll x) {
    if (left_.empty() || x <= *left_.rbegin()) {
        left_.insert(x);
        sumL += x;
    } else {
        right_.insert(x);
        sumR += x;
    }
    balance();
}

void remove(ll x) {
    if (x <= *left_.rbegin()) {
        left_.erase(left_.find(x));
        sumL -= x;
    } else {
        right_.erase(right_.find(x));
        sumR -= x;
    }
    balance();
}

ll cost() {
    ll median = *prev(left_.end());
    ll result = median * (int) left_.size() - sumL;
    result += sumR - median * (int) right_.size();
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < n; i++) {
        add(v[i]);
        if (i >= k - 1) {
            cout << cost() << " ";
            remove(v[i - k + 1]);
        }
    }
}
