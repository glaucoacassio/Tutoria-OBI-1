/**
 *   Author: glaucoacassioc
 *   Created on 26.09.2020, 13:02:41
**/

#include <bits/stdc++.h>
#define MAX 300000
using namespace std;

vector<int> adj[MAX];
vector<int> res;
int in[MAX];

bool Kahns(int n) {
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i<=n-1; i++) {
		if(in[i] == 0) {
   			pq.push(i);
		}
	}
	while(!pq.empty()) {
		int cur = pq.top();
		res.push_back(cur);
		pq.pop();
		for(int child : adj[cur]) {
   			in[child]--;
   			if(in[child] == 0) {
   				pq.push(child);
   			}
	     } 
	}
	return res.size() == n;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int j=0; j<=m-1; j++) {
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		in[y]++;
	}
	if(!Kahns(n)) {
		 cout<<'*'<<endl;
	} else {
		for(int no : res) {
			cout << no << endl;
		}
	}
	return 0;
}
