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

struct waveletTree{
	int n;
	vector<vector<int>> tree;
	vector<int> merge(vector<int>& a,vector<int>& b){
		vector<int> res;
		for(int x: a){
			res.push_back(x);
		}
		for(int x: b){
			res.push_back(x);
		}
		sort(res.begin(), res.end());
		return res;
	}
	void build(vector<int>& a,int node,int nl,int nr){
		if(nl == nr){
			tree[node].push_back(a[nl]);
			return;
		}
		else{
			int mid=(nl+nr)/2;
			build(a,2*node,nl,mid);
			build(a,2*node+1,mid+1,nr);
			tree[node]=merge(tree[2*node], tree[2*node+1]);
		}
	}
	void init(vector<int>& a,int _n){
		n=_n;
		tree = vector<vector<int>> (4*n);
		build(a,1,0,n-1);
	}
	int smaller_count(int node,int nl,int nr,int ql,int qr,int x){
		if(ql > nr || qr < nl){
			return 0;
		}
		if(ql <= nl && qr >= nr){
			int i=upper_bound(tree[node].begin(), tree[node].end(), x)-tree[node].begin();
			return i;
		}
		int mid=(nl+nr)/2;
		int left=smaller_count(2*node,nl,mid,ql,min(qr, mid),x);
		int right=smaller_count(2*node+1,mid+1,nr,max(ql, mid+1),qr,x);
		return left+right;		
	}
	int greater_count(int node,int nl,int nr,int ql,int qr,int x){
		if(ql > nr || qr < nl){
			return 0;
		}
		if(ql <= nl && qr >= nr){
			int i=lower_bound(tree[node].begin(), tree[node].end(), x)-tree[node].begin();
			return (int)tree[node].size()-i;
		}
		int mid=(nl+nr)/2;
		int left=greater_count(2*node,nl,mid,ql,min(qr, mid),x);
		int right=greater_count(2*node+1,mid+1,nr,max(ql, mid+1),qr,x);
		return left+right;		
	}
};
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