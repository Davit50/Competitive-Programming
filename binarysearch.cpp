#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vec = vector<int>;
using vvec = vector<vector<int>>;

//780B
int binsearch(vector<int> &v, int &id) {
    int start = 0;
    int end = v.size() - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (id <= v[mid]) end = mid;
        else start = mid + 1;
    }
    return start + 1;
}

int main() {
    vec v;
//    for (int i = 0; i < 11; i++) {
//        v.push_back(i);
//    }
    v.push_back(6);
    v.push_back(8);
    v.push_back(9);
    sort(v.begin(), v.end());
//    auto it1 = lower_bound(v.begin(), v.end(), 7);
    auto it1 = upper_bound(v.begin(), v.end(), 6);
    cout << *it1 << " ";
    int index1 = it1 - v.begin();
    cout << index1 << endl;
}



// Ternary Search

//    double eps = 1e-7;
//    double l = -1e9, r = 1e9;
//    double mid1, mid2;
//    while (r - l > eps) {
//        mid1 = l + (r - l) / 3;
//        mid2 = r - (r - l) / 3;
//        check(mid1) > check(mid2) ? l = mid1 : r = mid2;
//    }
//
//    cout << setprecision(10) << mid1 << endl;
//
//}



//      int l = 0, r = cur.size() - 1;
//        while (l <= r) {
//            int mid = (l + r) / 2;
//            if (ok(cur, mid, k))r = mid-1;
//            else l = mid+1;
//        }

