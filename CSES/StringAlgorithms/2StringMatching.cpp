#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e6+10;
int kmp[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string n,p;
  cin>>n>>p;
  n=p+'#'+n;
  for(int i=1; i<n.size(); i++){
    int j= kmp[i-1];
    while(j>0 && n[i] != n[j]){
      j = kmp[j-1];
    }
    if(n[i] == n[j]){
      j++;
    }
    kmp[i] = j;
  }
  int ans =0;
  for(int i=p.size(); i<n.size(); i++){
    if(kmp[i]==p.size()){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}

