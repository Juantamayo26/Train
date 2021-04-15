//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1970
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>

ll pot(ll a, ll b){
  ll ans =1;
  while(b){
    if(b&1){
      ans=(ans*a)%1000L;
    }
    a=(a*a)%1000L;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; 
  cin>>t;
  while(t--){
    int n, k;
    cin>>n>>k;
    double power = (double) k*log10(n);
    double first3 = pow(10, power - floor(power))*100;
    cout<<(int)first3<<"..."<<setw(3) << setfill('0') <<pot(n, k)<<endl;
  }
	return 0;
}

