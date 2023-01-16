#pragma once

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
const ll mod = 1e9 + 7;
const int INF = 1e9;

using namespace std;

long long max_weights(int N, int M, vector<int> X, vector<int> Y, vector<int> W) {
    bool isok = 1;
    bool isok2 = 1;
    bool isok3 = 1;
    for (int i = 0; i < M; i++) {
        if (X[i] & 1)isok = 0;
        if (X[i] > 1)isok2 = 0;
        if (Y[i] >= 1)isok3 = 0;
    }
    if (isok) return accumulate(W.begin(), W.end(), 0ll);
    if (isok2) {
        ll res = 0;
        vector<ll> p1(N), p2(N);
        for (int i = 0; i < M; ++i) {
            if (X[i] == 0)p1[Y[i]] = W[i];
            if (X[i] == 1)p2[Y[i]] = W[i];
        }
        for (int i = 1; i < N; i++) {
            p1[i] += p1[i - 1];
            p2[i] += p2[i - 1];
        }
        res = max(p1[N - 1], p2[N - 1]);
        if (N > 2) {
            for (int i = 0; i < N; i++) res = max(res, p2[N - 1] + p1[i] - p2[i]);
        }
        return res;
    }
    if (isok3) {
        vector<ll> dp(N, 0);
        vector<ll> v(N);
        for (int i = 0; i < M; i++) v[X[i]] = W[i];
        dp[0] = 0;
        dp[1] = max(v[0], v[1]);
        dp[2] = max({dp[0], dp[1], v[0] + v[2]});
        for (int i = 3; i < N; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2]);
            dp[i] = max(dp[i], dp[i - 2] + max(v[i], v[i - 1]));

            dp[i] = max(dp[i], dp[i - 3] + v[i] + v[i - 2]);

        }
//        for (int i = 0; i < N; i++)cout << dp[i] << " ";
        return dp[N - 1];

    }

// #4 subtask
    int K = 8;
    vector<ll> dp(N, 0);
    vector<vector<ll>> v(N, vector<ll>(K + 1));
    for (int i = 0; i < M; i++) v[X[i]][Y[i] + 1] = W[i];
    vector<vector<ll>> prefix(N, vector<ll>(K + 1));
    prefix = v;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) prefix[i][j] += prefix[i][j - 1];
    }
    dp[0] = 0;
    dp[1] = max(prefix[0][K], prefix[1][K]);
//    dp[2] = max({dp[0], dp[1], prefix[0][N - 1] + prefix[2][N - 1]});
    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2]);
        dp[i] = max(dp[i], dp[i - 2] + max(prefix[i - 1][K], prefix[i][K]));
//
        for (int a = 0; a <= K; a++) {
            for (int b = 0; b <= K; b++) {
                for (int c = 0; c <= K; c++) {
                    ll calc = 0;
                    if (a >= b && b >= c) {
                        calc = prefix[i - 1][a] - prefix[i - 1][b] + prefix[i][b] - prefix[i][c];
                    } else if (a >= max(b, c) && b <= c) {
                        calc = prefix[i - 1][a] - prefix[i - 1][b];
                    } else if (b >= max(a, c)) {
                        calc = prefix[i - 2][b] + prefix[i][b];
                    } else if (c >= max(a, b) && b >= a) {
                        calc = prefix[i - 1][c] - prefix[i - 1][b] + prefix[i - 2][b] - prefix[i - 2][a];
                    } else if (c >= max(a, b) && b <= a) {
                        calc = prefix[i - 1][c] - prefix[i - 1][b];
                    }
                    if (i - 3 >= 0) dp[i] = max(dp[i], dp[i - 3] + calc);
                    else dp[i] = max(dp[i], calc);
                }
            }
        }
    }
//        for (int i = 0; i < N; i++)cout << dp[i] << " ";
    return dp[N - 1];

}



//10 9
//0 0 1
//1 0 1
//2 0 1
//3 0 1
//4 0 10
//5 0 1
//6 0 1
//7 0 1
//8 0 1
