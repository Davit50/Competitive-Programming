#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> col;
vector<vector<int>> gp;

bool dfs(int u) {
    col[u] = 1;
    for (int &v: gp[u]) {
        if (col[v] == 0 && dfs(v)) return 1;
        else if (col[v] == 1) return 1;
    }
    col[u] = 2;
    return 0;
}

int main() {
    cin >> n >> m;
    col = vector<int>(n);
    gp = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gp[--u].push_back(--v);
    }
    for (int i = 0; i < n; i++) {
        if (col[i] == 0 && dfs(i)) {
            cout << "Cycle";
            return 0;
        }
    }
    cout << "Acyclic";
}