#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int a, b, n;
    cin>>a>>b>>n;
    int ans =1;
    while(a%2==0){
      a=a/2;
      ans*=2;
    }
    while(b%2==0){
      b=b/2;
      ans*=2;
    }
    cout<<(ans>=n?"YES":"NO")<<endl;
  }
  
  return 0;
}

