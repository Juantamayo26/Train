#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n, ans=0;
  cin>>n;
  for(long long int i=1; i<=n; i++){
    ans = ((i*i)*((i*i)-1)/2)-(4*(i-1)*(i-2));
    cout<<ans<<endl;
  }
}

