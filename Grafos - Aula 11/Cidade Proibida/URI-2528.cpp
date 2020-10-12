/**
 *   Author: glaucoacassioc
 *   Created on 12.10.2020, 15:06:24
**/

#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> adj;
enum { NAO_VISITADO, VISITADO };

int32_t main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin) ;
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int c, r, e, n, m;
		
	while(cin >> n >> m) {
		adj.assign(n+1, vi());
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		cin >> c >> r >> e;
		vi dist(n+1, INF);
		dist[c] = 0;
		
		queue<int> q;
		q.push(c);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i = 0; i < (int)adj[u].size(); i++) {
				int v = adj[u][i];
				if(dist[v] == INF && v != e) {
					dist[v] = dist[u]+1;    
					q.push(v);
				}
			}
		}
		cout << dist[r] << endl;
	}
	return 0;
}
