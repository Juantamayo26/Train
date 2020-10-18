#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n, ans=0;
  cin>>n;
  for(long long int i=5; i<=n; i*=5){
    ans+=(n/i);
  }
  cout<<ans<<endl;
}

