#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  vector<pii>s;
  for(int i=0; i<n; i++){
    int a,b; cin>>a>>b;
    s.push_back({b,a});
  }
  sort(s.begin(), s.end());
  int in=0;
  int ans=1;
  in = s[0].first;
  for(int i=1; i<n; i++){
    if(s[i].second>=in){
      in = s[i].first;
      ans++;
    }
  }
  cout<<ans<<endl;
  
}

