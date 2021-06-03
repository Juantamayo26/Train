#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<long long> vi;
#define INF 1000000000
#define endl '\n'
const ll M = 1e9+7;

vector<vi> multimat(vector<vi> &a, vector<vi> &b){
  vector<vi>ans = {
    {0, 0},
    {0, 0}
  };
  int n = a.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        ans[i][j] = ((a[i][k]%M*b[k][j]%M)+ans[i][j])%M;
      }
    }
  }
  return ans;
}

vector<vi>powermat(vector<vi> &a, ll b){
  vector<vi>ans = {
    {1, 0},
    {0, 1}
  };
  while(b){
    if(b&1){
      ans = multimat(ans,a);
    }
    a = multimat(a, a);
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  if(n == 0){
    cout<<0<<endl;
    return 0;
  }
  if( n == 1){
    cout<<1<<endl;
    return 0;
  }
  vector<vi>a = {
    {1, 1}, 
    {1, 0} 
  };
  vector<vi> ans = powermat(a, n-2);
  cout<<(ans[0][0]+ans[1][0])%M<<endl;
	return 0;
}

//puentes 
//puntos de articulacion
// componentes fuertemente conexos

