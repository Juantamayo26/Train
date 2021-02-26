#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
const int k = 25;
ll st[maxi][k+1];
ll a[maxi];

void sparse(int n){
  for(int i=0;i<n; i++){
    st[i][0] = a[i];
  }
  for(int j=1; j<=k; j++){
    for(int i=0;i+(1<<j)<=n; i++){
      st[i][j] = st[i][j-1]+st[i+(1<<(j-1))][j-1];
    }
  }
}

ll query(int n, int l, int r){
  ll sum = 0;
  l--;
  r--;
  for(int i=k; i>=0; i--){
    if((1<<i)<= r-l+1){
      sum+=st[l][i];
      cout<<st[l][i]<<endl;
      l+=1<<i;
    }
  }
  return sum;
}

ll query2(int n, int l, int r){
  ll sum = 0;
  l--;
  r--;
  int len = r-l+1;
  for(int i=0; len; i++){
    if(len&1){
      sum += st[l][i];
      l = l+(1<<i);
    }
    len>>=1;
  }
  return sum;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  int t;
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sparse(n);
  for(int i=0;i<10;i++){
    for(int j=0;j<10; j++){
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
