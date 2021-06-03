#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define INF 1000000000
#define endl '\n'
const int mod = 10007;

vector<vi> multimat(vector<vi> &a, vector<vi> &b){
  int n = a.size();
  vector<vi> ans = vector<vi>(n, vector<ll>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        ans[i][j] = (a[i][k]*b[k][j]+ans[i][j])%mod;
      }
    }
  }
  return ans;
}

vector<vi> powermat(vector<vi> a, ll b){
  vector<vi> ans = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0,0,1, 0}, {0,0,0,1}};
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
  int t; cin>>t;
  for(int i=1; i<=t; i++){
    ll n;
    ll a, b ,c;
    cin>>n>>a>>b>>c;
    if(n<=2){
      cout<<"Case "<<i<<": "<<0<<endl;
      continue;
    }
    vector<vi>mat = {{a, b, 1, 0},{0, 0, 0, 1},{0,0,1, 0}, {1,0,0,0}};
    
    vector<vi> res = powermat(mat, n-2);
    ll ans = (res[0][2]*c)%mod;
    cout<<"Case "<<i<<": "<<ans<<endl;
  }
	return 0;
}

