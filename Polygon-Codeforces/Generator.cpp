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
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
const int INF = 2e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);



int main() {
    srand(time(0));
    int test_cases = 50;
    while (test_cases--) {
        string name = "../Polygon-Codeforces/TestCases/test" + to_string(test_cases) + ".txt";
        freopen(name.c_str(), "w", stdout);

        int n = rand() % 100;
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            int x = rand() % 10000;
            cout << x << " ";
        }
    }
}