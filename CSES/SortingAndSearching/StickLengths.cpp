#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
int a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  int sum=0;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a, a+n);
  ll ans =0;
  ll ans1 =0;
  if(n&1){
    for(int i=0;i<n;i++){
      ans+=abs(a[n/2] - a[i]);
    }
  }else{
    for(int i=0;i<n;i++){
      ans+=abs(a[n/2] - a[i]);
      ans1+=abs(a[(n/2)+1] - a[i]);
    }
    ans= min(ans, ans1);
  }
  cout<<ans<<endl;
  return 0;
}

