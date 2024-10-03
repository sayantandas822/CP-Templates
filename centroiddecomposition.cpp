#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n";
using namespace std;

#ifdef LOCAL
#include "debuglib.h"
#else
#endif

struct LCA{
	const int N = 21;
	int n;
	vector<vector<int>> adj, up;
	vector<int> depth;
	void dfs(int v,int p){
		up[v][0]=p;
		if(p != -1){
			depth[v]=depth[p]+1;
		}
		for(int i=1;i<N;i++){
			up[v][i]=up[up[v][i-1]][i-1];
		}
		for(int x: adj[v]){
			if(x != p){
				dfs(x, v);
			}
		}
	}
	LCA(vector<vector<int>>& a,int _n){
		n=_n;
		depth = vector<int> (n);
		adj=a;
		up = vector<vector<int>> (n, vector<int> (N));
		dfs(0, 0);
	}
	int find_lca(int a,int b){
		if(depth[a] > depth[b]){
			swap(a, b);
		}
		int d=depth[b]-depth[a];
		for(int i=0;i<N;i++){
			if(d & (1 << i)){
				b=up[b][i];
			}
		}
		assert(depth[a] == depth[b]);
		if(a == b){
			return a;
		}
		for(int i=N-1;i>=0;i--){
			if(up[a][i] != up[b][i]){
				a=up[a][i];
				b=up[b][i];
			}
		}
		return up[a][0];
	}
	int dist(int a,int b){
		int lca=find_lca(a, b);
		int res=depth[a]+depth[b]-2*depth[lca];
		return res;
	}
};
struct CentroidTree{
	int n;
	vector<vector<int>> adj;
	vector<int> sz, par, best;
	vector<bool> vis;
	CentroidTree(int _n){
		n=_n;
		adj=vector<vector<int>> (n);
		vis = vector<bool> (n);
		sz = vector<int> (n);
		par = vector<int> (n);
		
		// problem specific
		best = vector<int> (n, n+1);
	}
	void edge(int a,int b){
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int find_size(int v, int p=-1){
		if(vis[v]){
			return 0;
		}
		sz[v]=1;
		for(int x: adj[v]){
			if(x != p){
				sz[v] += find_size(x, v);
			}
		}
		return sz[v];
	}
	int find_centroid(int v,int p,int n){
		for(int x: adj[v]){
			if(x != p){
				if(!vis[x] && sz[x] > n/2){
					return find_centroid(x,v,n);
				}
			}
		}
		return v;
	}
	void build(int v=0, int p=-1){
		find_size(v, -1);
		
		int c=find_centroid(v, -1, sz[v]);
		vis[c]=true;
		par[c]=p;
		for(int x: adj[c]){
			if(!vis[x]){
				build(x,c);
			}
		}
	}
};
// problem specific implementation
void test_cases(){
	
}
int32_t main(){
	fastio;
	int t=1;
	//cin >> t;
	while(t--){
		test_cases();
	}
}