#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 5010;
vector<int>used(5010);

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    vector<pii>s;
    int n; cin>>n;
    for(int i=1;i<=n;i++){
      int aux; cin>>aux;
      s.push_back({aux, i});
    }
    vector<pii>ans;
    for(int i=0;i<n;i++){
      for(int j=i+1; j<n;j++){
        if(s[i].first != s[j].first){
          used[i]=1; used[j]=1;
          ans.push_back({i+1, j+1});
          break;
        }
      }
    }
    bool k = true;
    for(int i=0;i<n;i++){
      if(!used[i]){ k=false; }
    }
    if(ans.size()>0&&k){
      cout<<"YES"<<endl;
      for(auto i: ans){
        cout<<i.first<<" "<<i.second<<endl;
      }
    }else{
      cout<<"NO"<<endl;
    }
    for(int i=0;i<n;i++){
      used[i]=0;
    }
  }
  return 0;
}

