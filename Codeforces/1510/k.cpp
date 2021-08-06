#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'
const int maxi = 2010;

int a[maxi];
int b[maxi];

void op1(int *a, int n){
  for(int i=0; i<2*n; i+=2){
    swap(a[i], a[i+1]);
  }
}

void op2(int *a, int n){
  for(int i=0; i<n; i++){
    swap(a[i], a[i+n]);
  }
}

bool checkans(int *a, int n){
  for(int i=1; i<2*n ;i++){
    if(a[i] < a[i-1]){
      return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  for(int i=0; i<2*n; i++){
    cin>>a[i];
  }
  int ans = INT_MAX;
  for(int i=0; i<2; i++){
    for(int j=0; j<2*n; j++){
      b[j] = a[j];
    }
    for(int k=0; k<2*maxi; k++){
      if(checkans(b, n)){
        ans = min(ans, k);
      }
      if((i+k)%2 == 0){
        op1(b, n);
      }else{
        op2(b, n);
      }
    }
  }
  cout<<((ans>=INF)?-1:ans)<<endl;
  return 0;
}
