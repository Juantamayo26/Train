#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'

vector<vector<ll>> multimat(vector<vector<ll>> &a, vector<vector<ll>> &b){
  vector<vector<ll>> ans ={
    {0, 0},
    {0, 0}
  };
  int n = a.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        ans[i][j] += a[i][k]*b[k][j];
      }
    }
  }
  return ans;
}

vector<vector<ll>> powermat(vector<vector<ll>> &a, int b){
  vector<vector<ll>> ans ={
    {1, 0},
    {0, 1}
  };
  while(b){
    if(b&1){
      ans = multimat(ans, a);
    }
    a = multimat(a, a);
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  vector<vector<ll>>a = {
    {1, 1},
    {1 ,0}
  };

  vector<vector<ll>> ans = powermat(a, n-1);
  cout<<ans[0][0]+ans[0][1]<<endl;

  return 0;
}
