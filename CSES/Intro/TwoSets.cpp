#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  ll aux= n*(n+1)/2;
  if(aux&1){
    cout<<"NO"<<endl;
    return 0;
  }else{
    cout<<"YES"<<endl;
    aux/=2;  
    vector<int>s;
    vector<int>s1;
    while(n){
      if((aux-n)>=0){
        s.push_back(n);
        aux-=n;
      }else{
        s1.push_back(n);
      }
      n--;
    }
    cout<<s.size()<<endl;
    for(auto i:s){
      cout<<i<<" ";
    }
    cout<<endl;
    cout<<s1.size()<<endl;
    for(auto i:s1){
      cout<<i<<" ";
    }
    cout<<endl;
  }
}
