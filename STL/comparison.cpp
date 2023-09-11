#include<bits/stdc++.h>

using namespace std;
struct node {
    int x, y;
};


//this is the best way
//bool operator<(const node &a, const node &b) {
//    return a.x < b.x;
//}


bool cmp(const node &a, const node &b) {
    return a.x < b.x;
}

int main() {
    multiset<node, decltype(cmp) *> all(cmp);
}