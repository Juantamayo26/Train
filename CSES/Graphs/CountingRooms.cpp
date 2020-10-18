#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
char a[1000][1000];

void solve(int i,int j, int n, int m){
  if(i<0 || j<0 || i>=n || j>=m || a[i][j]=='#'){
    return;
  }
  a[i][j] = '#';
  solve(i+1,j,n,m);
  solve(i-1,j,n,m);
  solve(i,j-1,n,m);
  solve(i,j+1,n,m);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j]=='.'){
        ans++;
        solve(i,j,n,m);
      }
    }
  }
  cout<<ans<<endl;
}

