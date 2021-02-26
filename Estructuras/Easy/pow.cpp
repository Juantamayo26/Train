#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

ll funtion2(double a, int b){
  if(b==0){
    return 1;
  }
  ll ans = funtion2(a, b/2);
  if(b&1){
    ans=ans*ans*a;
  }else{
    ans=ans*ans;
  }
  return ans;
}

double funtion(double a, int b){
  double ans = 1;
  while(b){
    if(b&1||(b<0)){
      ans*=a;
    }
    a*=a;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  double a;
  int b;
  cin>>a>>b;
  cout<<funtion2(a, b)<<endl;
  return 0;
}

