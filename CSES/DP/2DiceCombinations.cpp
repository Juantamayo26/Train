#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 1e6;
const int M = 1e9+7;
vector<ll> dp(maxi);

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  dp[0] = 1;
  for(int i=1;i<=n;i++){
    for(int j=1; j<=min(i, 6); j++){
      if(i-j>=0){
        dp[i]= (dp[i]+dp[i-j])%M;
      }
    }
  }
  cout<<dp[n]<<endl;
}

