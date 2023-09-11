// __Davit__
#include <bits/stdc++.h>

#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define vr(v) v.begin(),v.end()

using namespace std;
using vec = vector<ll>;
using vvec = vector<vector<ll>>;
using str = string;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);


int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    // for removing duplicates
//    vec v{1, 2, 2, 2, 3, 4, 1, 1, 4, 5, 5, 5, 1};
//    v.erase(unique(vr(v)), v.end());
//    print(v);


//    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//
//    void solve(vector<int> &cur, int id) {
//
//
//        if (cur.size() == 7){
//         for (int i = 0; i < cur.size(); i++)cout << cur[i] << " ";
//    cout << "\n";
//        return;}
//        if (id == vec.size()) return;
//        cur.push_back(vec[id]);
//        solve(cur, id + 1);
//        cur.pop_back();
//        solve(cur, id + 1);
//    }
//
//
//    int main() {
//        vector<int> cur;
//        solve(cur, 0);
//    }



//lambda recursive

//    function<void(int)> dfs;
//    dfs = [&](int u) {
//        dfs(0);
//    };
//

// !important
//    multiset<tmp, decltype(cmp) *> all(cmp);
//
//    bool operator<(const elem &x, const elem &y) {
//        return x.tin < y.tin;
//    }


//
//    map<ll, ll> glb[21][21];
//    glb[l][r][v]++;

//subsets

//    int x = 10;
//    int b = 0;
//    do {
//        cout << b << "\n";
//    } while (b = (b - x) & x);










}




//-----------
// -> struct inside map or set

//    struct node {
//        int x, y;
//
//        bool operator<(const node &other) const {
//            return make_pair(x, y) < make_pair(other.x, other.y);
// //        return tie(x, y) < tie(other.y, other.x);
//        }
//    };
//
//
//    int main() {
//        node x = {1, 3};
//        map<node, int> m;
//        m[x] = 1;
//        cout << m[x];
//
//    }

