#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int,int>>> vpi;
const int inf = 1e9+7;


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t,s,n,c=0,T[1005];
  cin>>t>>s>>n;
  for(int i=1;i <= n;i++)
    cin>>T[i];
  T[0] = T[1];
  for(int i=1;i <= n;i++){
    c = s - c + T[i] - T[i-1];
    if(c > s)
      c=s; 
  }
  c -= t - T[n];
  if(c <= 0)
    cout<<"0\n";
  else
    cout<<c<<"\n";
}
