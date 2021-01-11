#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
const int k = 25;
int a[maxi];
int st[maxi][k+1];
int loga[maxi+1];

void sparse(int n){
  loga[1] = 0;
  for(int i=2;i<=n; i++){
    loga[i] = loga[i/2]+1;
  }
  for(int i=0; i<n; i++){
    st[i][0] = a[i];
  }
  for(int j=1; j<=k; j++){
    for(int i=0; i+(1<<j)<=n; i++){
      st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
  }
}

int query(int n,int l,int r){
  l--; r--;
  int j =  loga[r-l+1];
  return min(st[l][j], st[r-(1<<j)+1][j]);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, t;
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sparse(n);
  while(t--){
    int a, b;
    cin>>a>>b;
    cout<<query(n, a, b)<<endl;
  }
  
  return 0;
}

