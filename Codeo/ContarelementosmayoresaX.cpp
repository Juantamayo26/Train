#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 200;
ll a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  ll q;
  cin>>q;
  while(q--){
    ll aux;
    cin>>aux;
    ll ans=0;
    for(int i=0; i<n; i++){
      if(a[i]>aux){
        ans++;
      }
    }
    cout<<ans<<endl;
  }

  
}

