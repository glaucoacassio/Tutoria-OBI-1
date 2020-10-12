/**
 *   Author: glaucoacassioc
 *   Created on 12.10.2020, 17:26:19
**/

#include <bits/stdc++.h>
#define INF 0x7f7f7f7
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

enum { NAO_VISITADO, VISITADO };
vi dfs_num;
vector<vi> adj;
int componentes;

void dfs(int u) {
	dfs_num[u]=VISITADO;
	for(int i=0; i<(int)adj[u].size(); i++) {
		int v = adj[u][i];
		if(dfs_num[v] == NAO_VISITADO) 
			dfs(v);
	}
}

int32_t main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin) ;
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n, m, tc = 1;
	cin >> t; 
	while(t--) {
		cin >> n >> m;
		adj.assign(n+1, vi());
		for(int i=1; i<=m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		componentes = 0;
		dfs_num.assign(n+1, NAO_VISITADO);
		for(int i=1; i<=n; i++) {
			if(dfs_num[i] == NAO_VISITADO) {
				++componentes, dfs(i);
			}
		}
		cout << "Caso #" << tc++ <<": ";
		if(componentes-1 == n || componentes-1 == 0) cout << "a promessa foi cumprida" << endl;
		else cout << "ainda falta(m) " << componentes-1 << " estrada(s)" << endl;
	}

	return 0;
}
