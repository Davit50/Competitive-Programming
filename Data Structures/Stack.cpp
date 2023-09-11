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
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);
//    freopen("x.in", "r", stdin);
//    freopen("x.out", "w", stdout);

//mt19937 mt(time(nullptr));


int main() {
//    we need to count [Sum of minimum elements of all subarrays]
//    for each element x we found number of elements strictly bigger than x in his left and same for his right then
//    we need just to multiply them to find number of segments that x is minimum there...
//    [10,10,1,10,10,10]
//    x is 1 there
//    there are 2 numbers on the left and 3 numbers on the right
//    out answer will be [3 * 4 * x]

    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)cin >> p[i];
    vector<pair<ll, ll>> borders(n);
    stack<int> st;
    st.push(0);
    borders[0].ff = 0;
    for (int i = 1; i < n; i++) {
        while (st.size() && p[st.top()] > p[i]) st.pop();
        if (st.empty())borders[i].ff = 0;
        else borders[i].ff = st.top() + 1;
        st.push(i);
    }
    borders[n - 1].ss = n - 1;
    st = stack<int>();
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        while (st.size() && p[st.top()] > p[i])st.pop();
        if (st.empty())borders[i].ss = n - 1;
        else borders[i].ss = st.top() - 1;
        st.push(i);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) res += ((abs(i - borders[i].ff) + 1) * (abs(i - borders[i].ss) + 1)) * p[i];


}