#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

vector<ll> s; 

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll x, n;
  while(cin>>x>>n){
    for(int i=0; i<n; i++){
      ll aux;
      cin>>aux;
      s.push_back(aux);
    }
    ll aux = x*1e7;
    sort(s.begin(), s.end());
    ll i=0;
    ll j=n-1;
    while(i<j){
      ll aux2 = s[i]+s[j];
      if(aux2==aux){
        break;
      }
      if(aux2>aux){
        j--;
      }else
        i++;
    }
    if(i<j)
      cout<<"yes "<<s[i]<<" "<<s[j]<<endl;
    else
      cout<<"danger"<<endl;
    s.clear();
  }
}

