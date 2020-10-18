#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  cout<<n<<" ";
  while(n!=1){
    if(n&1){
      n=(n*3)+1;
    }else{
      n=n/2;
    }
    cout<<n<<" ";
  }
  
}

