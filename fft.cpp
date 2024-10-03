#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define endl '\n';
#define __builtin_popcount(x) __builtin_popcountll(x)
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

#ifdef LOCAL
#include "debuglib.h"
#else
#endif

const int INF=1e17;
const int M=1e9+7;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

void read(vector<int>& a,int n){
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
}
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;
        
	// break into even and odd poly
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    // calculate the fft for the even and the odd poly
    fft(a0, invert);
    fft(a1, invert);

	// merge the result for the even and odd poly to get the answer for 
	// actual poly
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a,vector<int> const& b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n=1;
	 while (n < a.size() + b.size()) 
        n <<= 1;
	fa.resize(n);
	fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for(int i=0;i<n;i++){
		fa[i]*=fb[i];
	}
	fft(fa, true);
	vector<int> result(n);
	for(int i=0;i<n;i++){
		result[i]=round(fa[i].real());
	}
	return result;
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