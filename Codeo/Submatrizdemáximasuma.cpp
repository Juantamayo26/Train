#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 60;
ll a[maxi][maxi];
ll p[maxi][maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  for(int i=1;i<=n; i++){
    for(int j=1; j<=m; j++){
      cin>>a[i][j];
      p[i][j]=(a[i][j]+p[i-1][j]+p[i][j-1])-p[i-1][j-1];
    }
  }
  ll ans=-1e9;
  ll aux=0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      aux=-1e9;
      for(int i1=i;i1<=n; i1++){
        for(int j1=j; j1<=m; j1++){
          aux=max(aux, p[i1][j1]-p[i-1][j1]-p[i1][j-1]+p[i-1][j-1]);
        }
      }
      ans = max(ans, aux);
    }
  }
  cout<<ans<<endl;
}
