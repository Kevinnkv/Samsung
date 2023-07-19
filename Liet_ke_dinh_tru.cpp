#include <bits/stdc++.h>
using namespace std;

int V,E;
vector<int> adj[1001];
bool vs[1001];

void dfs(int u){
    vs[u] = 1;
    for(int x : adj[u]){
        if(vs[x] == 0){
            dfs(x);
        }
    }
}

void Solve(){
    int cnt = 0;
    memset(vs,0,sizeof(vs));
    for(int i=1;i<=V;i++){
        if(vs[i] == 0){
            cnt ++;
            dfs(i);
        }
    }
    
    for(int i=1;i<=V;i++){
    	memset(vs,0,sizeof(vs));
    	vs[i] = 1;
    	int new_cnt = 0; // dem so tp lt sau khi loai bo dinh i
    	for(int j=1;j<=V;j++){
    		if(vs[j] == 0){
    			new_cnt++;
    			dfs(j);
			}
		}
		if(new_cnt > cnt) cout << i << " "; // dinh i lam tang so tp lt
	}
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> V >> E;
        for(int i = 1; i <= V; i++){
            adj[i].clear(); 
        }
        while(E--){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        Solve();
    }
    return 0;
}

