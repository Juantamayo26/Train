#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string a;
  cin>>a;
  char aux = a[0];
  ll ans = 0;
  ll aux2 = 0;
  for(int i=0; i<a.length(); i++){
    if(a[i] == aux){
      aux2++;
      ans = max(ans, aux2);
    }else{
      aux = a[i];
      aux2 = 1;
    }
  }
  cout<<ans<<endl;
  
}

