#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define rv(v) v.rbegin(),v.rend()

using namespace std;
const int MOD = 1000000007;


struct Matrix {
    ll a[2][2] = {{0, 0},
                  {0, 0}};

    Matrix operator*(const Matrix &another) {
        Matrix product;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    product.a[i][k] += a[i][j] * another.a[j][k];
                    product.a[i][k] %= MOD;

                }
            }
        }
        return product;
    }

};

Matrix binpow(Matrix a, ll power) {
    Matrix res;
    for (int i = 0; i < 2; i++)res.a[i][i] = 1;

    while (power) {
        if (power & 1) {
            res = res * a;
        }
        a = a * a;
        power >>= 1;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    Matrix mt;
    mt.a[0][0] = 0;
    mt.a[0][1] = 1;
    mt.a[1][0] = 1;
    mt.a[1][1] = 1;
    Matrix res = binpow(mt, N);

    cout << res.a[0][1] << endl;
}