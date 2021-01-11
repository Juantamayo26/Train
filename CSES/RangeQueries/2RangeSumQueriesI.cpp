#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
const int k = 25;
ll a[maxi];
ll st[maxi][k+1];


void segment(int n){
  for(int i=0;i<n;i++){
    st[i][0] = a[i];
  }
  for(int j=1;j<=k ;j++){
    for(int i=0;i+(1<<j)<=n; i++){
      st[i][j] = st[i][j-1]+st[i+(1<<(j-1))][j-1];
    }
  }
}


int query(int n, int l, int r){
  ll sum = 0;
  r--;
  l--;
  for(int i=k; i>=0; i--){
    if((1<<i)<=r-l+1){
      sum += st[l][i];
      l+=(1<<i);
    }
  }
  return sum;
}



int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n,t;
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  segment(n);
  for(int i=0;i<10; i++){
    for(int j=0; j<10; j++){
      cout<<st[i][j]<<" ";
    }
    cout<<endl;
  }
  while(t--){
    int a, b;
    cin>>a>>b;
    cout<<query(n, a, b)<<endl;
  }
  
  return 0;
}

