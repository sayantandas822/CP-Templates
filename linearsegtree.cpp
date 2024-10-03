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
 
struct LinearSegtree{
	int n;
	vector<int> tree;
	vector<int> lazy_a, lazy_d, L, R;
	void build(vector<int>& a,int node,int nl,int nr){
		L[node]=nl, R[node]=nr;
		if(nl == nr){
			tree[node]=a[nl];
		}
		else{
			int mid=(nl+nr)/2;
			build(a,2*node,nl,mid);
			build(a,2*node+1,mid+1,nr);
			tree[node]=tree[2*node]+tree[2*node+1];
		}
	}
	void init(vector<int>& a){
		n=1;
		while(n < (int)a.size()){
			n*=2;
		}
		a.resize(n);
		tree = vector<int> (2*n);
		lazy_a = vector<int> (2*n);
		lazy_d = vector<int> (2*n);
		L = vector<int> (2*n);
		R = vector<int> (2*n);
		build(a,1,0,n-1);
	}
	void push_down(int node){
		if(lazy_a[node]){
			int a=lazy_a[node], d=lazy_d[node];
			int terms=R[node]-L[node]+1;
			int to_add=(2*a+(terms-1)*d)*terms/2;
			tree[node]+=to_add;
			lazy_a[node]=lazy_d[node]=0;
			if(L[node] != R[node]){
				lazy_a[2*node]+=a;
				lazy_d[2*node]+=d;
				lazy_a[2*node+1]+=a+(R[2*node]-L[2*node]+1)*d;
				lazy_d[2*node+1]+=d;
			}
		}
	}
	int query(int node,int ql,int qr){
		if(ql > R[node] || qr < L[node]){
			return 0;
		}
		push_down(node);
		if(ql <= L[node] && qr >= R[node]){
			return tree[node];
		}
		else{
			int left=query(2*node,ql,qr);
			int right=query(2*node+1,ql,qr);
			return left+right;
		}
	}
	void update(int node,int ql,int qr,int a,int d){
		push_down(node);
		if(ql > R[node] || qr < L[node]){
			return;
		}
		if(ql <= L[node] && qr >= R[node]){
			lazy_a[node]+=a;
			lazy_d[node]+=d;
			push_down(node);
		}
		else{
			update(2*node,ql,qr,a,d);
			// intersection of L[2*node], R[2*node] and ql, qr
			int lterms=min(R[2*node], qr)-max(L[2*node], ql)+1;
			lterms=max(0ll, lterms);
			update(2*node+1,ql,qr,a+lterms*d,d);
			tree[node]=tree[2*node]+tree[2*node+1];
		}
	}
};
void test_cases(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	LinearSegtree T;
	T.init(a);
	while(q--){
		int type, l, r;
		cin >> type >> l >> r;
		--l, --r;
		if(type == 1){
			T.update(1,l,r,1,1);
		}
		else{
			cout << T.query(1,l,r) << endl;
		}
	}
}
int32_t main(){
	fastio;
	int t=1;
	//cin >> t;
	while(t--){
		test_cases();
	}
}
