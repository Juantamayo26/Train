#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  vector<pair<int, int>>s;
  for(int i=0;i<n;i++){
    int a, b;
    cin>>a>>b;
    s.push_back({a, i+1});
    s.push_back({b, i+1});
  }
  sort(s.begin(), s.end());
  int i=1, ans = -1;
  for(int i=0;i<s.size(); i++){
    cout<<s[i].first<<" "<<s[i].second<<endl;
  }
  while(i<s.size()){
    if(s[i-1].first <= s[i].first){
      if(s[i-1].second != s[i].second){
        ans = s[i].second;
        break;
      }
    }
    i++;
  }
  cout<<ans<<endl;
  return 0;
}

