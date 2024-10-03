#include<bits/stdc++.h>
#define int long long
#define __builtin_popcount(x) __builtin_popcountll(x)
#define print1(a) for(auto x:a)cerr << x <<' ';cerr <<endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define print2(a,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++)cerr<<a[i][j]<<" ";cerr << endl;}
#define debug(x) cerr << x << endl;
#define print(a) for(auto x: a)cout << x << ' ';cout << endl;
#define debugp(x) cerr << x.first << ' ' << x.second << endl;
#define endl '\n';
const int INF=1e17;
const int M=1e9+7;
using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
struct KRUSKAL{
	vector<array<int,3>> edges;
	vector<int> taken, parent, sz;
	int n, m;
	KRUSKAL(vector<array<int,3>>& edge,int nodes){
		edges=edge;
		sort(edges.begin(), edges.end());
		m=edges.size(), n=nodes;
		taken = vector<int> (m);
		parent = vector<int> (n);
		sz = vector<int> (n,1);
		iota(parent.begin(),parent.end(),0);
	}
	int find_parent(int x){
		if(parent[x] == x){
			return x;
		}
		return parent[x]=find_parent(parent[x]);
	}
	int same(int a,int b){
		return find_parent(a) == find_parent(b);
	}
	void merge(int a,int b){
		int pa=find_parent(a), pb=find_parent(b);
		if(sz[pa] < sz[pb]){
			swap(pa,pb);
		}
		sz[pa]+=sz[pb];
		parent[pb]=pa;
	}
	void MST(){
		for(int i=0;i<m;i++){
			int x=edges[i][1], y=edges[i][2];
			if(!same(x,y)){
				merge(x,y);
				taken[i]=true;
			}
		}
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