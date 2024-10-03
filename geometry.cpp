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

// all about points
struct pt{
	int x, y;
	pt(): x(0), y(0) {}
	pt(int _x, int _y): x(_x), y(_y){}
	pt operator + (const pt& p) const {return pt(x+p.x, y+p.y);}
	pt operator - (const pt& p) const {return pt(x-p.x, y-p.y);}
	int cross(const pt& p) const {return x*p.y-y*p.x;}
	int dot(const pt& p) const {return x*p.x+y*p.y;}
	int cross(const pt& a, const pt& b){ return (a-*this).cross(b-*this);}
	int dot(const pt& a, const pt& b){ return (a-*this).dot(b-*this);}
	int sqrLen(){return this->dot(*this);}
};
// check if they are anti clockwise or not
int anticlockwise(vector<pt>& points){
	int n=points.size(), clk=0;
	for(int i=0;i+2<n;i++){
		pt a=points[i], b=points[i+1], c=points[i+2];
		int prod=a.cross(b-a, c-b);
		if(prod){
			clk |= (prod > 0);
			break;
		}
	}
	return clk;
}
// prepare the points for all the queries
void prepare(vector<pt>& points){
	int n=points.size();
	if(!anticlockwise(points)){
		reverse(points.begin(), points.end());
	}
}
int inter(int a, int b, int c, int d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	return max(a, c) <= min(b, d);
}
int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

int segment_inter(vector<pt>& c){
	if(c[1].cross(c[0], c[2]) == 0 && c[1].cross(c[0], c[3]) == 0){
		// collinear
		return (inter(c[0].x, c[1].x, c[2].x, c[3].x)
		&& inter(c[0].y, c[1].y, c[2].y, c[3].y));
	}
	return sgn(c[0].cross(c[1], c[2])) != sgn(c[0].cross(c[1], c[3])) &&
           sgn(c[2].cross(c[3], c[0])) != sgn(c[2].cross(c[3], c[1]));
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