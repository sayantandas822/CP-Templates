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
void test_cases(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<vector<int>> Q(m);
	for(int i=0;i<m;i++){
		int l, r;
		cin >> l >> r;
		--l, --r;
		Q[i]={l, r, i};
	}
	int block_size=sqrt(n+.0)+1;
	vector<int> res(m);
	sort(Q.begin(),Q.end(),[&](vector<int>& x,vector<int>& y){
		return make_pair(x[0]/block_size,x[1]) < make_pair(y[0]/block_size,y[1]);
	});
	int ans=0;
	const int MAXN = 2e5+5;
	vector<int> cnt(MAXN);
	auto add = [&](int i){
		if(a[i] < MAXN){
			if(cnt[a[i]] == a[i]){
				ans--;
			}
			cnt[a[i]]++;
			if(cnt[a[i]] == a[i]){
				ans++;
			}
		}
	};
	auto remove = [&](int i){
		if(a[i] < MAXN){
			if(cnt[a[i]] == a[i]){
				ans--;
			}
			cnt[a[i]]--;
			if(cnt[a[i]] == a[i]){
				ans++;
			}
		}
	};
	auto get_answer = [&](){
		return ans;
	};
	int cur_l=0, cur_r=-1;
	for(auto& q: Q){
		while(cur_l > q[0]){
			cur_l--;
			add(cur_l);
		}
		while(cur_r < q[1]){
			cur_r++;
			add(cur_r);
		}
		while(cur_l < q[0]){
			remove(cur_l);
			cur_l++;
		}
		while(cur_r > q[1]){
			remove(cur_r);
			cur_r--;
		}
		res[q[2]]=get_answer();
	}
	for(int x: res){
		cout << x << endl;
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