#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  map<int,int>s;
  for(int i=0;i<n; i++){
    int x;
    cin>>x;
    s[x]++;
  }
  cout<<s.size()<<endl;
}

