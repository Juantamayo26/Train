#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 500;
int a[maxi][maxi];
int aux[maxi][maxi];
int movi[4] = {1, -1, 0, 0};
int movj[4] = {0, 0, -1, 1};

void bfs(int i, int j, int k){
  if(k==0){
    return;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int n, m;
    cin>>n>>m;
    bool band = false;
    bool band2 = false;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin>>a[i][j];
        if(a[i][j]>0){
          band = true;
        }
      }
    }
    if(!band){
      cout<<"YES"<<endl;
      for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
          cout<<a[i][j]<<" ";
        }
        cout<<endl;
      }
      continue;
    }
    for(int i=0; i<n;i++){
      for(int j=0;j<m;j++){
        if(((i==0 && j>0) || (i>0 && j==0) || (i==n-1 && j>0) || (j==m-1 && i>0))){
          if(a[i][j]>3){
            band2 =true;
          }
          aux[i][j] = 3;
        }
        if((i==0&&j==0) || (i==n-1&&j==0) || (i==n-1&&j==m-1) || (i==0&&j==m-1)){
          if(a[i][j]>2){
            band2 =true;
          }
          aux[i][j] = 2;
        }
        if(i>0 && j>0&& i<n-1 && j<m-1){
          if(a[i][j]>4){
            band2 =true;
          }
          aux[i][j] = 4;
        }
      }
    }
    if(band2){
      cout<<"NO"<<endl;
      continue;
    }
    cout<<"YES"<<endl;
    for(int i=0; i<n;i++){
      for(int j=0;j<m;j++){
        cout<<aux[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}

