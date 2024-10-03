#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

#ifdef LOCAL
#include "debuglib.h"
#else
#endif

void test_cases(){
	srand(time(0));
	int n;
	cin >> n;
	cout << n << endl;
	for(int i=0;i<n;i++){
		cout << 1+rand()%n << ' ';
	}	
	cout << endl;
}
int32_t main(){
	fastio;
	int t=1;
	cin >> t;
	while(t--){
		test_cases();
	}
}