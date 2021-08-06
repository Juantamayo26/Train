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
  int w,h;
  cin>>w>>h;
  long double p = sqrt((w*w)+(h*h));
  cout<<setprecision(10)<<fixed<<w+h-p<<"\n";
  return 0;
}
