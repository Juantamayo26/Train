#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 1e6;
int a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int x; cin>>x;//numero a buscar
  int i=0, j=n-1;
  sort(a, a+n);
  while(i<=j){
    int mid= (i+j)/2;
    if(a[mid]<=x){
      i=mid+1;
    }else
      j=mid-1;
  }
  cout<<a[j]<<endl;
}

