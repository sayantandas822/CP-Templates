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
struct segtree{
	vector<int> tree;
	int n;
	// constructor for segment tree
	segtree (vector<int> a){
		int tmp=a.size();
		while(__builtin_popcount(tmp) != 1){
			++tmp;
			a.push_back(0);
		}
		n=tmp;
		tree = vector <int> (2*tmp);
		for(int i=tmp;i<2*tmp;i++){
			tree[i]=a[i-tmp];
		}
		for(int i=tmp-1;i>=1;i--){
			tree[i]=tree[2*i]+tree[2*i+1];
		}
	}
	segtree (int tmp){
		while(__builtin_popcount(tmp) != 1){
			++tmp;
		}
		n=tmp;
		tree = vector <int> (2*tmp);
	}
	// get the query for range l to r
	int get(int node,int node_low,int node_high,int query_low,int query_high){
		if(query_low > node_high || query_high < node_low){
			return 0;
		}
		if(query_low <= node_low && query_high >= node_high){
			return tree[node];
		}
		int mid=(node_low+node_high)/2;
		int left=get(2*node,node_low,mid,query_low,query_high);
		int right=get(2*node+1,mid+1,node_high,query_low,query_high);
		return left+right;
	}
	// updates in segment tree
	void update(int pos,int val){
		tree[n+pos]=val;
		for(int i=(n+pos)/2;i>=1;i/=2){
			tree[i]=tree[2*i]+tree[2*i+1];
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