#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pi pair<int, int>



vector<pi>s;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  int aux=1e9;
  for(int i=0; i<n; i++){
    int a,b; cin>>a>>b;
    aux = min(aux,b);
    s.push_back({a,b});
  }
  sort(s.begin(), s.end());
  int in=0;
  int ans=1;
  in = aux;
  for(int i=0; i<n; i++){
    if(s[i].first>=in){
      in = s[i].second;
      ans++;
    }
  }
  cout<<ans<<endl;
}

