#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define INF 1000000000
#define endl '\n'

vector<vi> multimat(vector<vi> &a, vector<vi> &b, ll mod){
  int n=a.size();
  vector<vi> ans = {{0,0},{0,0}};
  for(int i=0 ;i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        ans[i][j] += ((a[i][k]%mod)*(b[k][j]%mod))%mod;
      }
    }
  }
  return ans;
}

vector<vi> powermat(vector<vi> a, ll b, ll mod){
  vector<vi> ans = {{1, 0},{0, 1}};
  while(b){
    if(b&1){
      ans = multimat(ans, a, mod);
    }
    a = multimat(a,a, mod);
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  vector<vi> mat = {{1,1}, {1, 0}};
  for(int i=1; i<=t; i++){
    int a, b, m;
    ll n;
    cin>>a>>b>>n>>m;
    if(n == 0){
      cout<<"Case "<<i<<": "<<a<<endl;
      continue;
    }
    ll mod = ((ll)pow(10, m));
    vector<vi> resp = powermat(mat, n-1, mod);
    ll ans = (resp[0][0]*b)+(a*resp[0][1]);
    cout<<"Case "<<i<<": "<<ans%mod<<endl;
  }
	return 0;
}

