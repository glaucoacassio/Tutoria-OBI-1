/**
 *   Author: glaucoacassioc
 *   Created on 24.09.2020, 21:47:04
**/
// Topo Sort - Detectando Ciclos
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1610
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visitado;
vector<bool> onstack;
vector<int> toposort;

void dfs(int no, bool &esCiclico) {
    if(esCiclico) return;
    
    visitado[no] = true;
    onstack[no] = true;

    for(int vizinho: adj[no]) {
        if (visitado[vizinho] && onstack[vizinho]) {
            esCiclico = true;
            return;
        }
        if(!visitado[vizinho]) {
            dfs(vizinho, esCiclico);
        }
    }                

    onstack[no] = false;
    toposort.push_back(no);
}

bool topo(int no) {
    visitado[no] = true;
    onstack[no] = true;
    
    for(int vizinho: adj[no]) {
    		//se ja visitou e esse vertice ja na ta pilha existe um ciclo
        if(visitado[vizinho] && onstack[vizinho]) {  
            return true;
        //se nao foi visitado e o pai nao aparece no topo
        } else if(!visitado[vizinho] && topo(vizinho)) {
        		//existe um ciclo
            return true;
        }
    }
    onstack[no] = false;
    toposort.push_back(no);
    return false;
}

int32_t main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; cout.tie(NULL);
	int tt;
	cin>>tt;
	while(tt--) {
		int n, m;
		cin>>n>>m;
     	adj.assign(n+10, vector<int>());
    		visitado.assign(n, false);
    		onstack.assign(n, false);
          for(int i=0; i<m; i++) {
          	int a, b;
          	cin>>a>>b;
          	adj[a-1].push_back(b-1);	
          }
    		bool esCiclico = false;
    		for(int no = 1; no <= n; ++no) {
        		if(!visitado[no]) {
            		dfs(no, esCiclico);
            		if(esCiclico) break;
        		}
    		}
    		if(esCiclico) {
        		cout << "SIM" << endl;
    		} else {
    			cout << "NAO" << endl;
   		}
   		toposort.clear();
   	}
    	return 0;
}	
