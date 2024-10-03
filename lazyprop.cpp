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
	vector<int> t, marked, L, R, lazy;
	void build(vector<int>& a,int node,int nl,int nr){
		L[node]=nl, R[node]=nr;
		if(nl == nr){
			t[node]=a[nl];
		}
		else{
			int mid=(nl+nr)/2;
			build(a,2*node,nl,mid);
			build(a,2*node+1,mid+1,nr);
			t[node]=min(t[2*node],t[2*node+1]);
		}
	}
	segtree(vector<int>& a){
		int n=a.size();
		t = vector<int> (4*n);
		marked = vector<int> (4*n);
		L = vector<int> (4*n);
		R = vector<int> (4*n);
		lazy = vector<int> (4*n);
		build(a,1,0,n-1);
	}
	void push(int v) {
	    t[v*2] += lazy[v];
	    lazy[v*2] += lazy[v];
	    t[v*2+1] += lazy[v];
	    lazy[v*2+1] += lazy[v];
	    lazy[v] = 0;
	}
	void update(int v, int tl, int tr, int l, int r, int addend) {
	    if (l > r) 
	        return;
	    if (l == tl && tr == r) {
	        t[v] += addend;
	        lazy[v] += addend;
	    } else {
	        push(v);
	        int tm = (tl + tr) / 2;
	        update(v*2, tl, tm, l, min(r, tm), addend);
	        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
	        t[v] = min(t[v*2], t[v*2+1]);
	    }
	}
	
	int query(int v, int tl, int tr, int l, int r) {
	    if (l > r)
	        return INF;
	    if (l <= tl && tr <= r)
	        return t[v];
	    push(v);
	    int tm = (tl + tr) / 2;
	    return min(query(v*2, tl, tm, l, min(r, tm)), 
	               query(v*2+1, tm+1, tr, max(l, tm+1), r));
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