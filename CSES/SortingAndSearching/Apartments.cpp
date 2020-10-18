#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define ll long long
const int maxi = 2e5;
ll a[maxi];
ll b[maxi];
 
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n,m,k;
  cin>>n>>m>>k;
  for(int i=0;i<n; i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  sort(a,a+n);
  sort(b,b+m);
  int i=0;
  int j=0;
  int ans=0;
  while(j<m&&i<n){
    if(((a[i]+k)>=b[j])&&((a[i]-k)<=b[j])){
      ans++;
      i++;
      j++;
    }
    else if(b[j]<a[i]){
      j++;
    }else{
      i++;
    }
  }
  cout<<ans<<endl;
}
