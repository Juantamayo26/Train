#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 100;
int criba[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  criba[0]=1;
  criba[1]=1;
  for(int i=2; i*i<=maxi; i++){
    if(!criba[i]){
      for(int j=2; j*i<=maxi; j++){
        criba[i*j]=1;
      }
    }
  }
  for(int i=0; i<10; i++){
    cout<<criba[i]<<" ";
  }

  
}

