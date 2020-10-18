#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5;
ll a[maxi];
ll prefix[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    prefix[i] = a[i]+prefix[i-1];
  }
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<prefix[b]-prefix[a-1]<<endl;
  }
}

