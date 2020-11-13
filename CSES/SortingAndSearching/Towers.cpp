#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  multiset<int>s;
  for(int i=0, aux;i<n;i++){
    cin>>aux;
    auto x = s.upper_bound(aux);
    if(x!=s.end()){
      s.erase(x);
    }
    s.insert(aux);
  }
  cout<<s.size()<<endl;
  return 0;
}

