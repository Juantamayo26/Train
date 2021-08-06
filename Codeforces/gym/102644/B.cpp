#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'
#define REP(i, n) for(int i=0; i<(n); i++)
const int mod = 1e9+7;
const int n = 2;

struct Matrix{
  ll a[2][2] = {{0,0},{0,0}};
  Matrix operator *(const Matrix &other){
    Matrix ans;
    REP(i, n){
      REP(j, n){
        REP(k, n){
          ans.a[i][j] += (a[i][k]*other.a[k][j]);
          ans.a[i][j] %= mod;
        }
      }
    }
    return ans;
  }
};

Matrix power(Matrix &a, ll b){
  Matrix ans;
  REP(i, n) ans.a[i][i] = 1;
  while(b){
    if(b&1){
      ans = ans*a;
    }
    a = a*a;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n; cin>>n;
  Matrix single;
  single.a[0][0] = 19;
  single.a[0][1] = 6;
  single.a[1][0] = 7;
  single.a[1][1] = 20;
  cout<<power(single, n).a[0][0]<<endl;
	return 0;
}

