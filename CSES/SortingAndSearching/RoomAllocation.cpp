#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
vector<pair<int, pii>>s;


int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=0;i<n; i++){
    int a, b; cin>>a>>b;
    s.push_back(make_pair(a, pii(-1, i+1)));
    s.push_back(make_pair(b, pii(1, i+1)));
  }
  sort(s.begin(), s.end());
  stack<int>d;
  int cont=0;
  vector<int>ans(maxi);
  for(int i=0;i<s.size(); i++){
    if(s[i].second.first==-1){
      if(d.size()){
        ans[s[i].second.second]=(d.top());
        d.pop();
      }else{
        cont++;
        ans[s[i].second.second] = cont;
      }
    }else if(s[i].second.first==1){
      d.push(ans[s[i].second.second]);
    }
  }
  cout<<cont<<endl;
  for(int i = 1; i<=n; i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}

