//https://www.spoj.com/problems/LASTDIG/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>

ll pot(ll a, ll b){
  ll ans = 1;
  while(b){
    if(b&1){
      ans=(ans*a)%10;
    }
    a= (a*a)%10;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int a, b;
    cin>>a>>b;
    cout<<pot(a,b)<<endl;
  }
	return 0;
}

