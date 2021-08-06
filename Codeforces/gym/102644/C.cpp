#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define INF 1000000000
#define endl '\n'
#define REP(i, n) for(int i=0; i<(n); i++)
const int mod = 1000000007;
int n =2;
 
struct Matrix{
  vector<vi> a = vector<vi>(n, vi(n));
 // ll a[2][2] = {{0,0},{0,0}};
  Matrix operator *(const Matrix &other){
    Matrix ans;
    REP(i, n) {
      REP(j, n) {
        REP(k, n){
          ans.a[i][j] += (a[i][k]* other.a[k][j]);
          ans.a[i][j] %= mod;
        }
      }
    }
    return ans;
  }
};
 
Matrix expo_power(Matrix a, ll b){
  Matrix ans;
  for(int i=0; i<2; i++){
    ans.a[i][i] = 1;
  }
  while(b){
    if(b&1){
      ans = ans*a;
    }
    b>>=1;
    a = a*a;
  }
  return ans;
}
 
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n; cin>>n;
  Matrix single;
  single.a[0][0] = 1;
  single.a[0][1] = 1;
  single.a[1][0] = 1;
  single.a[1][1] = 0;
  Matrix ans = expo_power(single,n);
  cout<<ans.a[0][1]<<endl;
	return 0;
}
