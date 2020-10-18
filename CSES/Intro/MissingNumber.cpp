#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  ll sum=0;
  for(int i=0; i<n-1; i++){
    ll aux;
    cin>>aux;
    sum+=aux;
  }
  cout<<n*(n+1)/2-sum<<endl;
  
}

