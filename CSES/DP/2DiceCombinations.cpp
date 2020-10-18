#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 1e6;
ll dp[maxi];
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  memset(dp, 0, sizeof dp);
  int n;
  cin>>n;
  dp[0]=1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=6; j++){
      if(i-j>=0)
        dp[i]=dp[i]+dp[i-j];
    }
  }
  for(int i=0;i<=n; i++){
    cout<<dp[i]<<endl;
  }
  cout<<dp[n]<<endl;
}

