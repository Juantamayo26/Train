#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll pot(ll a, ll b){
	ll ans =1;
	while(b){
		if(b&1){
			ans*=a;
		}
		b>>=1;
		a=a*a;
	}
	return ans;
}


int main(){
	int a, b;
	cin>>a>>b;
	cout<<pot(a,b)<<endl;
	return 0;
}
