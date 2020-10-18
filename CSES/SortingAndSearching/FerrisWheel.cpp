#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
ll a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, x;
  cin>>n>>x;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int i=0;
  int j=n-1;
  sort(a, a+n);
  ll ans =0;
  while(i<=j){
    if(a[i]+a[j]<=x)
      i++;
    ans++;
    j--;
  }
  cout<<ans<<endl;
}
