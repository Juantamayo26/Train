#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2012;
const int MOD = 1000007;
int pascal[maxi][maxi];
int prefix[maxi];
ll sum =0;

void tpascal(){
  for(int i=0; i<=maxi-100; i++){
    pascal[i][0]=1;
    pascal[i][i+1] = 1;
    for(int j=0; j<i+2; j++){
      pascal[i+1][j+1] = (pascal[i][j] + pascal[i][j+1])%MOD;
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  tpascal();
  int cont=1;
  prefix[0]=1;
  for(int i=0; i<1001; i++){
    int sum =0; 
    for(int j=0; j<1001; j++){
      sum=(sum+pascal[i][j])%MOD;
    }
    //mod
    prefix[cont]=(prefix[cont-1]+sum)%MOD;
    cont++;
  }
  while(cin>>n>>m&&n!=-1&&m!=-1){
    ll ans =0;
    ans=(prefix[m]-prefix[n-1]+MOD)%MOD;
    cout<<ans<<endl;
  }
  
}

