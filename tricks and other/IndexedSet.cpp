#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    indexed_set s;
    s.insert(1);
    s.insert(2);

    s.insert(4);
    cout << *s.find_by_order(2) << endl;//element at a given position
    cout << s.order_of_key(2) << endl;//position of a given element

}
