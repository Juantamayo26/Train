#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 60;
int a[maxi][maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>a[i][j];
    }
  }
  int ans = -1e9;
  int aux =0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      for(int i1=i; i1<n; i1++){
        for(int j1=j; j1<m; j1++){
          aux=0;
          for(int x=i; x<=i1; x++){
            for(int y=j; y<=j1; y++){
              aux+= a[x][y];
            }
          }
          ans=max(ans, aux);
        }
      }
    }
  }
  cout<<ans<<endl;
}

