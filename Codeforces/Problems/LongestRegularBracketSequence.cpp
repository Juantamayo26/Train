#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e6+10;
int kmp[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string s;
  cin>>s;
  int i=0;
  int maxi = 0;
  while(s[i]==')'){
    i++;
  }
  while(i<s.size()){
    if(s[i]=='('){
      kmp[i] = 0;
    }else{
      if(kmp[i-1]>0){
        int aux = i - kmp[i-1]- 1;
        if(s[aux]=='('){
          kmp[i] = kmp[i-1]+2+kmp[aux-1];
       }
      }else{
        if(s[i-1]=='('){
          kmp[i]+=2+kmp[i-2];
        }
      //  cout<<kmp[i]<<endl;
      }
    }
    maxi = max(maxi, kmp[i]);
    i++;
  }
  i=0;
  int ans = 0;
  int temp = 0;
  while(i<s.size()){
//    cout<<kmp[i]<<" ";
    if(maxi == kmp[i]){
      ans++;
    }
    i++;
  }
//  cout<<endl;
  if(maxi==0){
    cout<<maxi<<" "<<1<<endl;
    return 0;
  }
  cout<<maxi<<" "<<ans<<endl;
  return 0;
}

