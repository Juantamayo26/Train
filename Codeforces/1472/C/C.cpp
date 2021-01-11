#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
int a[maxi];
int dp[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    int global =0;
    for(int i=n;i>0;i--){
      dp[i] = a[i];
      if(i+a[i] <=n){
        dp[i] += dp[i+a[i]];
      }
      global = max(dp[i], global);
    }
    cout<<global<<endl;
  }
  return 0;
}

