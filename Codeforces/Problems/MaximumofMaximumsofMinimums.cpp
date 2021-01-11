//https://codeforces.com/contest/872/problem/B
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e5+10;
const int k = 25;
int a[maxi];
int st[maxi][k+1];

void sparse(int n){
  for(int i=0;i<n;i++){
    st[i][0] = a[i];
  }
  for(int j=1; j<=k; j++){
    for(int i=0; i+(1<<j)<=n; i++){
      st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
  }
}


int query(int n, int l, int r){
  int ans = INT_MAX;
  int len = r-l+1;
  for(int i=0; len; i++){
    if(len&1){
      ans = min(ans, st[l][i]);
      l+=1<<i;
    }
    len>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, t;
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int mini = a[0];
  int maxi = a[0];
  for(int i=0;i<n;i++){
    mini = min(mini, a[i]);
    maxi = max(maxi, a[i]);
  }
  if(t==1){
    cout<<mini<<endl;
  }else if(t==2){
    sparse(n);
    int ans = a[0];
    for(int i=0;i<n-1;i++){
      ans = max({ans, query(n, 0, i),query(n,i+1 ,n-1)});
    }
    cout<<ans<<endl;
  }else{
    cout<<maxi<<endl;
  }
  
  return 0;
}

