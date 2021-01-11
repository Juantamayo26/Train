#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e6+10;
vector<int>kmp(maxi);

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string s;
  cin>>s;
  for(int i=1;i<s.size();i++){
    int j=kmp[i-1];
    while(j>0 && s[i]!=s[j]){
      j = kmp[j-1];
    }
    if(s[i]==s[j]){
      j++;
    }
    kmp[i] = j;
  }
  for(int i=0;i<s.size(); i++){
    cout<<kmp[i]<<" ";
  }
  return 0;
}

