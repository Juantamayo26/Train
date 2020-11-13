#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  cout<<"hola"<<endl;
  int sum = 0;
  for(int j=1; j<=n; j++){
    sum+=j*(n/j);
  }
  cout<<sum<<endl;
  
  return 0;
}

