#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int a; cin>>a;
    int ans = a%10;
    int aux = a;
    int cont=1;
    while(aux/10>0){
      aux=aux/10;
      cont++;
    }
    ans = ans*10;
    for(int i=cont+1; i<=4; i++){
      ans = ans-i;
    }
    cout<<ans<<endl;
  }
  return 0;
}

