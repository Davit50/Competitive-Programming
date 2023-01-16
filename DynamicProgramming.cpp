// __Davit__
#define _CRT_SECURE_NO_WARNINGS

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
const int INF = 1e9 + 5;


void pprint(vvec v) {
    for (ll i = 0; i < v.size(); i++) {
        for (ll j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print(vec v) {
    for (ll i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
//    Problem 1
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> a(n, vector<int>(m));
//    vector<vector<int>> dp(n, vector<int>(m));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> a[i][j];
//        }
//    }
//    dp[0][0] = a[0][0];
//    for (int i = 1; i < n; i++) {
//        dp[i][0] = dp[i - 1][0] + a[i][0];
//    }
//    for (int i = 1; i < m; i++) {
//        dp[0][i] = dp[0][i - 1] + a[0][i];
//    }
//
//    for (int i = 1; i < n; i++) {
//        for (int j = 1; j < m; j++) {
//            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
//        }
//    }
//    cout << dp[n - 1][m - 1];

    //    Problem 2.1

//        vec nums{1, 2, 3};
//        int n = 4;
//        vec dp(n + 1);
//
//        dp[0] = 1;
//        for (int i = 1; i <= n; i++) {
//            for (auto x: nums) {
//                if (i - x >= 0) {
//                    dp[i] += dp[i - x];
//                }
//            }
//        }
//        print(dp);

//    Problem 2.2

//
//    vec nums{1, 10};
//    int n = 11;
//    vec dp(n + 1, INF);
//    dp[0] = 0;
//    for (int i = 1; i <= n; i++) {
//        for (auto x: nums) {
//            if (i - x >= 0) {
//                dp[i] = min(dp[i], dp[i - x] + 1);
//            }
//        }
//    }
//    cout << dp[dp.size() - 1];

    //    Problem 2.3


}


//

//-------------------------problem 3.0 (Line of wines problem) (Errichto) --------------------------------
//#solution 1
//vector<int> v{2, 4, 6, 2, 5};
//int n = (int) v.size();
//vvec dp(n, vec(n, -1));
//
//int rec(int l, int r) {
//    if (dp[l][r] != -1)return dp[l][r];
//    int year = n - (r - l + 1) + 1;
//    dp[l][r] = max(
//            year * v[l] + rec(l + 1, r),
//            year * v[r] + rec(l, r - 1)
//    );
//    return dp[l][r];
//}
//
//int main() {
//    for (int i = 0; i < n; i++)dp[i][i] = v[i] * n;
//    cout << rec(0, n - 1);
//}
