#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
vector<int>a(maxi);

bool can(ll mid, int n, int x){
  ll ans = 0;
  for(int i=0;i<n;i++){
    ans+= (mid/a[i]);
    if(ans >= x){
      return true;
    }
  }
  return ans >= x;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, x;
  cin>>n>>x;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  
  ll i=0;
//  ll j=1e18+1;
  ll j=n*x;
  while(i<=j){
    ll mid = (i+j)/2;
    if(can(mid, n, x)){
      j=mid-1;
    }else{
      i=mid+1;
    }
  }
  cout<<i<<endl;
  return 0;
}

