#include <bits/stdc++.h>

using namespace std;

bool m_search(string word, vector<vector<int>> &trie) {
    int node = 0;
    for (int i = 0; i < (int) word.size(); i++) {
        char c = word[i];
        if (trie[node][c - 'a'] == 0) return false;
        node = trie[node][c - 'a'];
    }
    return true;
}


void m_insert(const string &word, vector<vector<int>> &trie) {
    int node = 0;
    for (char c: word) {
        if (trie[node][c - 'a'] == 0) {
            trie.push_back(vector<int>(26));
            trie[node][c - 'a'] = (int) trie.size() - 1;
        }
        node = trie[node][c - 'a'];
    }
}


int main() {
    vector<vector<int>> trie(1, vector<int>(26));
    vector<string> words{"apple"};
    for (string &x: words) {
        m_insert(x, trie);
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        bool ok = m_search(s, trie);
        if (ok)cout << "1";
        else cout << "0";
    }

}
