#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi =1e6+9;
const int maxii = 10000000;
int a[maxi];
int dp[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, x;
  fill(dp,dp+maxi,maxii);
  cin>>n>>x;
  for(int i=0;i<n; i++){
    cin>>a[i];
  }
  dp[0]=0;
  for(int i=1; i<=x; i++){
    for(int j=0; j<n; j++){
      if(i-a[j]>=0)
        dp[i]=min(dp[i], 1+dp[i-a[j]]);
    }
  }
  if(dp[x]==maxii){
    cout<<"-1"<<endl;
    return 0;
  }
  cout<<dp[x]<<endl;
}

