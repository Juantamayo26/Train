#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string s;
  cin>>s;
  int k;
    cin>>k;
  vector<int>a(26,0);
  int i=0;
  int j=1;
  a[s[i]-'a']++;
  int ans = INT_MAX;
  int cont = 1;
  if(k==cont){
    cout<<1<<endl;
    return 0;
  }
  while(j<s.size() && i<s.size()){
    if(a[s[j]-'a']==0){
      cont++;
    }
    a[s[j]-'a']++;
    while(cont==k){
      ans = min(ans, j-i+1);
      a[s[i]-'a']--;
      if(a[s[i]-'a']==0){
        cont--;
      }else{
        ans = min(ans, j-i+1); 
      }
      i++;
    }
    j++;
  }
  if(ans == INT_MAX){
    cout<<-1<<endl;
    return 0;
  }
  cout<<ans<<endl;
  return 0;
}

