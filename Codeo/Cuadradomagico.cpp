#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 110;
int a[maxi][maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n; j++){
      cin>>a[i][j];
    }
  }
  int sum1=0,sum2=0,sumd1=0,sumd2=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n; j++){
      if(i==j){
        sumd1+=a[i][j];
      }
      sum1+=a[i][j];
    }
    sum2+=a[i][0];
    sumd2+=a[i][n-1-i];
  }
  if(sumd1==sumd2&&(sum1/n)==sum2){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}

