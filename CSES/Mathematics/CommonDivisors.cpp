#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e6;
vector<int>s(maxi);

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    int aux; cin>>aux;
    s[aux]++;
  }
  int ans =1;
  for(int i=2;i<maxi; i++){
    int sum =0;
    for(int j=i; j<maxi; j+=i){
      sum+=s[j];
    }
    if(sum>1){
      ans = i;
    }
  }
  cout<<ans<<endl;
}
