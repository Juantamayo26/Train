#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'
const int maxi = 2010;

struct Matrix{
  double a[2][2]= {{0,0}, {0,0}};
  Matrix operator*(const Matrix &other){
    Matrix ans;
    for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
        for(int k=0; k<2; k++){
          ans.a[i][j] += a[i][k]*other.a[k][j];
        }
      }
    }
    return ans;
  }
};

Matrix powermat(Matrix &a, ll b){
  Matrix ans;
  for(int i=0; i<2; i++) ans.a[i][i] = 1;
  while(b){
    if(b&1){
      ans=ans*a;
    }
    a=a*a;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll k;
  double p; 
  cin>>k>>p;
  Matrix single;
  single.a[0][0] = (double)1-p;
  single.a[0][1] = p;
  single.a[1][0] = p;
  single.a[1][1] = (double)1-p;
  cout<<setprecision(10)<<fixed<<powermat(single, k).a[0][0]<<endl;
  return 0;
}
