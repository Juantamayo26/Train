#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
vector<pair<int, int>>s;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    int a, b; cin>>a>>b;
    s.push_back({a,1});
    s.push_back({b,-1});
  }
  sort(s.begin(), s.end());
  int aux= 0;
  int ans=0;
  for(int i=0; i<s.size(); i++){
    if(s[i].second==1){
      aux++;
    }else{
      aux--;
    }
    ans = max(aux,ans);
  }
  cout<<ans<<endl;
}

