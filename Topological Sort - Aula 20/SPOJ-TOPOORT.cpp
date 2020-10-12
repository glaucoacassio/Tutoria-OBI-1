/**
 *   Author: glaucoacassioc
 *   Created on 25.09.2020, 01:51:27
**/
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1610
#include<bits/stdc++.h>
#define MAX 10001
#define endl '\n'
using namespace std;

vector<int> adj[MAX];
vector<int> res;
int in[MAX];
 
bool Kahns(int n) {
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 1; i <= n; i++) {
		if(in[i] == 0) {
			pq.push(i);
		}
	}
	while(!pq.empty()) {
		int curr = pq.top();
		res.push_back(curr);
		pq.pop();
		for(int child : adj[curr]) {
			in[child]--;
			if(in[child] == 0)
			pq.push(child);
		}
	}
	return res.size() == n;
}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x, y, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		in[y]++;
	}
	if(!Kahns(n)) {
		cout<<"Sandro fails.";
	} else {
		for(int no : res)
		cout << no <<" ";
	}
}	
