#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void dfs(int u, int t, vector<int>& path, bool& found) {
    visited[u] = true;
    path.push_back(u);
    if (u == t) {
        found = true;
        return;
    }
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, t, path, found);
            if (found) return;
        }
    }
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> path;
        bool found = false;
        dfs(s, t, path, found);
        if (found) {
            for (int u : path) {
                cout << u << " ";
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}

