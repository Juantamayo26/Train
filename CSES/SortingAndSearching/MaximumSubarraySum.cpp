#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
vector<int>a(maxi);
ll p[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  for(int i=1; i<=n; i++){
    ll aux; cin>>aux;
    a[i]=aux;
  }
  ll max_c, max_g;
  max_c=max_g=a[1];
  for(int i=2; i<=n; i++){
    max_c = max((ll)a[i], (a[i]+max_c));
    cout<<max_c<<endl;
    if(max_c>max_g){
      max_g=max_c;
    }
  }
  cout<<max_g<<endl;
}

