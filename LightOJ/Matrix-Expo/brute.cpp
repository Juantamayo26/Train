#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'

int solve(int n, int a, int b, int c){
  if(n<=2){
    return 0;
  }
  return a*solve(n-1, a, b, c)+b*solve(n-3, a, b, c) + c;
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  while(t--){
    int n, a, b ,c;
    cin>>n>>a>>b>>c;
    cout<<solve(n, a, b, c)<<endl;
  }
  
	return 0;
}

