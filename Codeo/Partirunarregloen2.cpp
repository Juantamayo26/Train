#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 500011;
ll a[maxi];
ll prefix[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=0;i<n; i++){
    cin>>a[i];
  }
  int right=0;
  int left=a[0];
  for(int i=1;i<n; i++){
    right+=a[i];
  }
  for(int i=1;i<n; i++){
    if(left>0 && right < 0){
      cout<<i<<endl;
      return 0;
    }
    right= right - a[i];
    left+=a[i];
  }
  cout<<"Impossible"<<endl;
  return 0;
}

