#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5;
ll a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  ll ans = 0;
  ll aux2 = 0;
  for(int i=0; i<n; i++){
    ll aux;
    cin>>aux;
    if(aux<aux2){
      ans+=aux2-aux;
    }else{
      aux2=aux;
    }
  }
  cout<<ans<<endl;
}

