#include<bits/stdc++.h>
// #define int long long
#define print1(a) for(auto x:a)cerr << x <<' ';cerr <<endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define endl '\n';
const int INF=1e9+1;
const int M=1e9+7;
using namespace std;
int n, m;
vector<vector<int>> adj, rev_adj;
vector<int> order, used, component, roots, root_nodes, indeg;
void dfs1(int i){
	used[i]=1;
	for(int x: adj[i]){
		if(!used[x]){
			dfs1(x);
		}
	}
	order.push_back(i);
}
void dfs2(int i){
	used[i]=1;
	component.push_back(i);
	for(int x: rev_adj[i]){
		if(!used[x]){
			dfs2(x);
		}
	}
}
// finds scc and condensation graph
void find_scc(){
	order.clear();
	root_nodes.clear();
	used = vector<int> (n);
	indeg = vector<int> (n);
	roots = vector<int> (n);
	for(int i=0;i<n;i++){
		if(!used[i]){
			dfs1(i);
		}
	}
	reverse(order.begin(), order.end());
	used = vector<int> (n);
	for(auto& v: order){
		if(!used[v]){
			dfs2(v);
			// process the component here
			int root=component[0];
			root_nodes.push_back(root);
			for(int x: component){
				roots[x]=root;
			}
			component.clear();
		}
	}
	for(int i=0;i<n;i++){
		for(int x: adj[i]){
			int root_x=roots[x], root_i=roots[i];
			if(root_x != root_i){
				// adj_scc[root_i].push_back(root_x);
				++indeg[root_x];
			}
		}
	}
}
// this is used for this particular problem
// above this evrything is general
int good(){
	find_scc();
	int cnt=0;
	for(int v: root_nodes){
		cnt+=(indeg[v] == 0);
	}
	return (cnt == 1);
}
void test_cases(){
	
}
int32_t main(){
	fastio;
	int t=1;
	cin >> t;
	while(t--){
		test_cases();
	}
}