#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

int V, N;
vector<pair<int, pair<int, int>>> G, MST;
vector<int> parent;

int find(int i){
	while(i != parent[i]) i = parent[i];
	return i;
}

void kruskal(){
	int total_cost = 0;
	
	//MAKESET
	for(int i = 0; i < V; i++) parent.pb(i);
	
	//SORT
	sort(G.begin(), G.end());
	
	//CONNECTIONS & UNION
	for(int i = 0; i < N; i++){
		int u = find(G[i].second.first);
		int v = find(G[i].second.second);
		if(u != v){
			MST.pb(G[i]);
			//UNION
			parent[u] = parent[v];
			total_cost += G[i].first;
		} 
	}
	
	//PRINT
	cout << total_cost << endl;
	for(int i = 0; i < MST.size(); i++){
		printf("%c-%c %d\n", MST[i].second.first+'A', MST[i].second.second+'A', MST[i].first);
	}
}

int main(){
	cout << "Input Number of Switches: ";
	cin >> V;
	
	cout << "Input Number of Connections: ";
	cin >> N;
	
	
	for(int i = 0; i < N; i++){
		char a, b;
		int w;
		
		cin >> a >> b >> w;
		
    	G.pb(mp(w, mp(a-'A', b-'A')));
    }
    
    kruskal();
 
    return 0;
}



