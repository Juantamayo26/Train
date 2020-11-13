#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
//  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  vector<int>s(n);
  for(int i=0;i<n; i++){
    cin>>s[i];
  }
  //burbuja
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(s[i]>s[j]){
        swap(s[i], s[j]);
      }
    }
  }
  for(int i=0; i<n; i++){
    cout<<s[i]<<" ";
  }
  cout<<endl;
  
  return 0;
}

