// #include <bits/stdc++.h>
// using namespace std;
// CÃ¡ch thÃ´ng thÆ°á»ng 
// int n,m;
// vector <int> adj[10001];
// bool vs[10001];
// void dfs(int u){
//     vs[u]=1;
//     for(int x:adj[u]){
//         if(vs[x] == 0){
//             dfs(x);
//         }
//     }
// }

// void Solve(int x,int y){
//     dfs(x);
//     if(vs[y] == 0) cout << "NO" << endl;
//     else cout << "YES" << endl;
// }
// int main(){
//     int t; cin >> t;
//     while(t--){
//         memset(adj,0,sizeof(adj));
//         cin >> n >> m; // n dinh m canh
//         while(m--){
//             int u,v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         int q; cin >> q;
//         while(q--){
//             int x,y; 
//             cin >> x >> y;
//             memset(vs,0,sizeof(vs));
//             Solve(x,y);
//         }
//     }
//     system("pause");
//     return 0;
// }

#include <iostream> // cÃ¡ch dÃ¹ng tá»‘i Æ°u sá»­ dá»¥ng Disjont set
#include <vector>
using namespace std;

const int MAXN = 1000;
int parent[MAXN+1];

// HÃ m tÃ¬m táº­p há»£p (set) chá»©a Ä‘á»‰nh u
int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

// HÃ m gá»™p hai táº­p há»£p chá»©a u vÃ  v thÃ nh má»™t táº­p há»£p
void merge(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu != pv) parent[pu] = pv;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;

        // Khá»Ÿi táº¡o má»—i Ä‘á»‰nh lÃ  má»™t táº­p há»£p Ä‘á»™c láº­p
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Gá»™p cÃ¡c táº­p há»£p chá»©a Ä‘á»‰nh Ä‘Æ°á»£c ná»‘i bá»Ÿi cÃ¡c cáº¡nh
        while (m--) {
            int u, v; cin >> u >> v;
            merge(u, v);
        }

        // Kiá»ƒm tra truy váº¥n
        int q; cin >> q;
        while (q--) {
            int x, y; cin >> x >> y;
            if (find(x) == find(y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}