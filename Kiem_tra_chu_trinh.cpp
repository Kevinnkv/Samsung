#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int T, n, m;
int parent[N], sz[N];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        bool has_cycle = false;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            if (find(u) == find(v)) {
                has_cycle = true;
            } else {
                unite(u, v);
            }
        }
        if (has_cycle) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}