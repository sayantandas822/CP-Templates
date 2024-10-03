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

const int MAXN=500005;
int p=998244353, M=998244353;
int invfact[MAXN+1];
int invnum[MAXN+1];
int fact[MAXN+1];
void InverseofNumber(int p){
    invnum[0]=invnum[1]=1;
    for (int i=2;i<=MAXN;i++){
        invnum[i]=invnum[p%i]*(p-p/i)%p;
    }
}
// Function to precompute inverse of factorials
void InverseofFactorial(int p){
    invfact[0]=invfact[1]=1;
    // precompute inverse of natural numbers
    for (int i = 2; i <= MAXN; i++)
        invfact[i]=(invnum[i]*invfact[i-1])%p;
}
// Function to calculate factorial of 1 to MAXN
void factorial(int p){
    fact[0]=1;
    for (int i=1;i<=MAXN;i++) {
        fact[i]=(fact[i-1]*i)% p;
    }
}
int power(int a,int b){
	int res=1;
	while(b > 0){
		if(b & 1){
			res=(p+res*a)%p;
		}
		a=(p+a*a)%p;
		b/=2;
	}
	return res%p;
}
int C(int n,int r){
	if(n < r || r < 0){
		return 0;
	}
	int res=fact[n];
	res=(M+res*invfact[r])%M;
	res=(M+res*invfact[n-r])%M;
	return res;
}
void test_cases(){
	
}
signed main(){
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
    int t=1;
    //cin >> t;
    while(t--){
    	test_cases();
    }
}