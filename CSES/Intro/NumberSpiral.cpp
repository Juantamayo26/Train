#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  while(n--){
    ll ans=0;
    ll x, y;
    cin>>y>>x;
    if(y==1&&x==1){
      cout<<1<<endl;
      continue;
    }
    ll aux = max(x,y);
    if(aux&1){
      ans=(aux*aux)-abs(1-y)-abs(aux-x);
    }else{
      ans=(aux*aux)-abs(1-x)-abs(aux-y);
    }
    cout<<ans<<endl;
  }
  
}

