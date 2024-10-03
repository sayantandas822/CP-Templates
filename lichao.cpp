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
typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag
struct LiChao{
	int dot(point a, point b){
		return (conj(a) * b).x();
	}
	int f(point a, int x){
		return dot(a, {x, 1});
	}
	int n;
	vector<point> line;
	vector<int> used;
	void init(int _n){
		n=_n;
		line = vector<point> (4*n, {0, INF});
	}
	// insert a line (k, b) -> slope = k, intercept = b
	void add_line(int v, int l, int r, point nw) {
		used.push_back(v);
	    int m = (l + r) / 2;
	    bool lef = f(nw, l) < f(line[v], l);
	    bool mid = f(nw, m) < f(line[v], m);
	    if(mid) {
	        swap(line[v], nw);
	    }
	    if(r - l == 1) {
	        return;
	    } else if(lef != mid) {
	        add_line(2 * v, l, m, nw);
	    } else {
	        add_line(2 * v + 1, m, r, nw);
	    }
	}
	// get the minimum value over all the lines inserted
	ftype get(int x, int v, int l, int r) {
		used.push_back(v);
	    int m = (l + r) / 2;
	    if(r - l == 1) {
	        return f(line[v], x);
	    } else if(x < m) {
	        return min(f(line[v], x), get(x, 2 * v, l, m));
	    } else {
	        return min(f(line[v], x), get(x, 2 * v + 1, m, r));
	    }
	}
	void clear(){
		for(int v: used){
			line[v]={0, INF};
		}
		used.clear();
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