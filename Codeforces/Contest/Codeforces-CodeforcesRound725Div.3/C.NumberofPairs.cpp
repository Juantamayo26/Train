// time-limit: 2000
// problem-url: https://codeforces.com/contest/1538/problem/C
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'
const int maxi = 2e5+10;
int a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  while(t--){
    ll n, l, r;
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    ll ans = 0;
    sort(a, a+n);
    for(int i=0; i<n; i++){
      int L = lower_bound(a, a+n, l-a[i] )-a;
      L = max(L, i+1);
      int R = upper_bound(a, a+n, r-a[i])-a-1;
      if(R-L >= 0) ans+=R-L+1;
    }
    cout<<ans<<endl;
  }
	return 0;
}

