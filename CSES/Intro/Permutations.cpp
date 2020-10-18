#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  if(n<=3){
    cout<<"NO SOLUTION"<<endl;
    return 0;
  }
  for(int i=2; i<=n; i+=2){
    cout<<i<<" ";
  }
  for(int i=1; i<=n; i+=2){
    cout<<i<<" ";
  }
}

