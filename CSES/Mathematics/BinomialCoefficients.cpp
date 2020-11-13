#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e6+10;
const int M = 1e9+7;
ll dp[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  //a!/(b!*(a-b)!)
  int t; cin>>t;
  while(t--){
    int a, b;
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));
    dp[0]=1;
    int aux = max(a,b);
    for(int i=1; i<=aux; i++){
      dp[i] = (i*dp[i-1])%M;
    }
    cout<<dp[a]<<" "<<dp[b]<<endl;
    aux = (a-b+M)%M;
    cout<<aux<<endl;
    cout<<(dp[a]/((dp[b]*(dp[aux]))%M))<<endl;
  }
  return 0;
}

