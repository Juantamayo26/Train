#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;
int a[55];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    bool l=false;
    ll ans=0;
    ll unos=0;
    int left=0;
    int i=0;
    i=n-1;
    while(a[i]==0){
      a[i]=1;
      i--;
    }
    for(int i=0;i<n;i++){
      if(a[i]==1){
        left = i;
        l = true;
        unos++;
      }else if(a[i] == 0 && l){
        ans++;
      }
    }
    if(unos>1){
      cout<<ans<<endl;
    }else{
      cout<<0<<endl;
    }
  }
  
  return 0;
}

