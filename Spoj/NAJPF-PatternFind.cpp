#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e6+10;
vector<ll>kmp(maxi);
vector<ll>ans;

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    string q;
    cin>>s>>q;
    s=q+'#'+s;
    fill(kmp.begin(), kmp.begin()+maxi, 0);
    for(ll i=1; i<s.size(); i++){
      ll j= kmp[i-1];
      while(j>0 && s[i]!=s[j]){
        j= kmp[j-1];
      }
      if(s[i]==s[j]){
        j++;
      }
      kmp[i] = j;
    }
    ans.clear();
    for(ll i=q.size(); i<s.size(); i++){
      if(kmp[i]==q.size()){
        ans.push_back(i-(2*q.size())+1);
      }
    }
    if(ans.size()==0){
      cout<<"Not Found"<<endl;
      cout<<endl;
      continue;
    }
    cout<<ans.size()<<endl;
    for(auto i: ans){
      cout<<i<<" ";
    }
    cout<<endl<<endl;
  }
  
  return 0;
}

