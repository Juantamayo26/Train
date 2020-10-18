#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const ll maxi = 1e6+7;
ll griba[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  for(int i=2; i<maxi; i++){
    for(int j=i; j<maxi; j+=i)
      griba[j]++;
  }
  cin>>n;
  while(n--){
    ll aux;
    cin>>aux;
    cout<<griba[aux]+1<<endl;
  }
}
