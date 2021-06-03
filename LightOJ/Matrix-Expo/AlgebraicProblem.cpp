#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<unsigned long long> vi;
#define INF 1000000000
#define endl '\n'

vector<vi> multimat(vector<vi> &a, vector<vi> &b){
  vector<vi>ans = {{0, 0},{0, 0}};
  ll n = a.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        ans[i][j] += (a[i][k]*b[k][j]);
      }
    }
  }
  return ans;
}

vector<vi> powermat(vector<vi> a, unsigned long long b){
  vector<vi> ans = {{1,0},{0, 1}};
  while(b){
    if(b&1){
      ans = multimat(ans, a);
    }
    b>>=1;
    a = multimat(a, a);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  unsigned long long p, q, n;
  int t; cin>>t;
  for(int i=1; i<=t; i++){
    cin>>p>>q>>n;
    if(n==2){
      cout<<"Case "<<i<<": "<<2<<endl;
      continue;
    }
    vector<vi>mat = {{p, -q},{1, 0}};
    vector<vi> ans = powermat(mat, n-1);
    cout<<"Case "<<i<<": "<<ans[0][0]*p+ans[0][1]*2<<endl;
  }
	return 0;
}
