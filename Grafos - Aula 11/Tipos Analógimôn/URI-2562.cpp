/**
 *   Author: glaucoacassioc
 *   Created on 08.10.2020, 11:33:23
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> adj;
vi dfs_num;
int numCC;

enum { NAO_VISITADOS, VISITADOS };

void dfs(int u)
{
	dfs_num[u] = VISITADOS;
	++numCC;
	for(int i=0; i<(int)adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(dfs_num[v] == NAO_VISITADOS)
			dfs(v);
	}
}

int32_t main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin) ;
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, analogimon;
	while(cin>>n>>m) 
	{
		adj.assign(n+1, vi());
		for(int i=0; i<m; i++)
		{
			int a, b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);	
		}
		numCC=1;
		dfs_num.assign(n+1, NAO_VISITADOS);
		cin>>analogimon;
		dfs(analogimon);
		cout<<numCC<<endl;
	}
	return 0;
}                             
