#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define vr(v) v.begin(),v.end()
#define rv(v) v.rbegin(),v.rend()
using namespace std;


struct P {
    ll x, y;

    void read() {
        cin >> x >> y;
    }

    P operator-(const P &other) const {
        return {x - other.x, y - other.y};
    }

    void operator-=(const P &other) {
        x -= other.x;
        y -= other.y;
    }

    ll operator*(const P &other) const {
        return x * other.y - other.x * y;
    }

    ll triangle(const P &b, const P &c) const {
        return (b - *this) * (c - *this);
    }

};

//two lines intersection
bool intersect(P p1, P p2, P p3, P p4) {
    if ((p2 - p1) * (p4 - p3) == 0) {
        //two segments are parallel
        if (p1.triangle(p2, p3) != 0) {
            return 0;
        }
        //check if two bounding boxes intersect
        for (int rep = 0; rep < 2; rep++) {
            //rectangle A is on left from rectangle B or A is below B
            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                return 0;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return 1;
    }
    for (int rep = 0; rep < 2; rep++) {
        ll sign1 = p1.triangle(p2, p3);
        ll sign2 = p1.triangle(p2, p4);
        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            return 0;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return 1;
}


int main() {

    int n;
    cin >> n;
    vector<P> polygon(n);
    for (int i = 0; i < n; i++)polygon[i].read();
    ll area = 0;
    for (int i = 0; i < n; i++) {
        area += polygon[i] * polygon[i + 1 == n ? 0 : i + 1];
    }
    cout << abs(area) / 2.0 << endl;
}