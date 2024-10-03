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
const int N=1e6+6;
vector<int> phi(N + 1);
int lpf[N+1];
int mobius[N+1];
void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++){
        phi[i] = i;
    }
	phi[1]=0;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
void least_prime_factor(){
    for (int i = 2; i < N; i++)
        if (!lpf[i])
            for (int j = i; j < N; j += i)
                if (!lpf[j])
                    lpf[j] = i;
}
void Mobius(int n)
{
    for (int i = 1; i < n; i++) {
        if (i == 1)
            mobius[i] = 1;
        else {
            if (lpf[i / lpf[i]] == lpf[i])
                mobius[i] = 0;
            else
                mobius[i] = -1 * mobius[i / lpf[i]];
        }
    }
    
}
void test_cases(){
	
}
int32_t main(){
	fastio;
	phi_1_to_n(N);
	least_prime_factor();
	Mobius(N);
	int t=1;
	cin >> t;
	while(t--){
		test_cases();
	}
}