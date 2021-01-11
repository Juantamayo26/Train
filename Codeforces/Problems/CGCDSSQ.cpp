#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e5+10;
const int k = 25;
int a[maxi];
ll st[maxi][k+1];
int loga[maxi+1];

void sparse(int n){
  loga[1]=0;
  for(int i=2; i<=n; i++){
    loga[i]=loga[i/2]+1;
  }
  for(int i=0;i<n;i++){
    st[i][0]=a[i];
  }
  for(int j=1; j<=k; j++){
    for(int i=0; i+(1<<j)<=n ;i++){
      st[i][j] = __gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]); 
    }
  }
}

ll query(int l, int r){
  int j= loga[r-l+1];
  return __gcd(st[l][j], st[r-(1<<j)+1][j]);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int t; cin>>t;
  unordered_map<ll , ll>s;
  sparse(n);
  for(int i=0;i<n;i++){
    int j = i;
    int k = a[i];
    while(j<n){
      int l=j, r=n-1;
      while(r-l>1){
        int mid = (l+r)/2;
        if(query(i, mid)==k){
          l=mid;
        }else{
          r=mid;
        }
      }
      s[k]+=(l-j+1);
      j = l+1;
      k = __gcd(k, a[j]);
    }
  }
  while(t--){
    int aux;
    cin>>aux;
    cout<<s[aux]<<endl;
  }
  return 0;
}

