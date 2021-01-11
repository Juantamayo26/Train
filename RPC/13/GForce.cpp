#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e5+10;
int a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  map<pair<int, int>, int>s;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1; j<n; j++){
      s[make_pair(a[i], a[j])]++;
    }
  }
  cout<<s.size()+1<<endl;
  
  return 0;
}

