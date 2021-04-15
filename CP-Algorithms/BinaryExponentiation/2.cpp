//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=310
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>

ll pot(ll a, ll b, ll m){
  ll ans = 1;
  while(b){
    if(b&1){
      ans=(a*ans)%m;
    }
    a=(a*a)%m;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll a, b, m;
  while(cin>>a>>b>>m){
    cout<<pot(a, b, m)<<endl;
  }
	return 0;
}

