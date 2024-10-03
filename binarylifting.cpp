#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define endl '\n';
#define __builtin_popcount(x) __builtin_popcountll(x)
using namespace std;

#ifdef LOCAL
#include "debuglib.h"
#else
#endif

const int INF=1e17;
const int M=1e9+7;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
struct LCA{
	int n;
	const int K=20; // change K based on requirement
	vector<int> depth, vis;
	vector<vector<int>> adj, dp;
	void dfs(int s,int p){
		if(vis[s]){
			return;
		}
		vis[s]=1;
		if(s){
			depth[s]=depth[p]+1;
			dp[s][0]=p;
			for(int i=1;i<K;i++){
				dp[s][i]=dp[dp[s][i-1]][i-1];
			}
		}
		for(int x: adj[s]){
			if(x != p){
				dfs(x, s);
			}
		}
	}
	LCA(vector<vector<int>>& tree){
		adj=tree;
		n=adj.size();
		depth = vector<int> (n);
		vis = vector<int> (n);
		dp = vector<vector<int>> (n, vector<int> (K));
		dfs(0, -1);
	}
	int find(int x,int y){
		if(depth[x] > depth[y]){
			swap(x, y);
		}
		// x is always at lower depth than y
		int d=depth[y]-depth[x];
		for(int i=K-1;i>=0;i--){
			if(d & (1ll << i)){
				y=dp[y][i];
			}
		}
		if(x == y){
			return x;
		}
		assert(depth[x] == depth[y]);
		for(int i=K-1;i>=0;i--){
			if(dp[x][i] != dp[y][i]){
				x=dp[x][i], y=dp[y][i];
			}
		}
		return dp[x][0];
	}
};
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