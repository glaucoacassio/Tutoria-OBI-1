/**
 *   Author: glaucoacassioc
 *   Created on 25.09.2020, 23:32:55
**/

#include <bits/stdc++.h>
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
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin) ;
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	while(cin >> n >> m && (n || m)) {
		for(int j = 0; j <= n + 5; j++) {
            	adj[j].clear();
          	in[j] = 0;
        	}
        	res.clear();
	     for(int i = 1; i <= m; i++) {
	     	int x, y;
	     	cin >> x >> y;
	     	adj[x].push_back(y);
	     	in[y]++;
	  	}
	  	if(!Kahns(n)) {
	  		cout << -1 << endl;	
	  	} else {
			for(int no : res) {
		     	cout << no <<" ";
			}
	  		cout << endl;
	 	}
	}
  	return 0;
}
	     
