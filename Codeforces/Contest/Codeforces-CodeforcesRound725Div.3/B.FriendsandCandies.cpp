// time-limit: 2000
// problem-url: https://codeforces.com/contest/1538/problem/B
#include <bits/stdc++.h>

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
    int n; cin>>n;
    ll sum = 0;
    for(int i=0; i<n; i++){
      cin>>a[i];
      sum+=a[i];
    }
    if(sum%n != 0){
      cout<<-1<<endl;
      continue;
    }
    ll part = sum/n;
    int ans = 0;
    for(int i=0; i<n; i++){
      if(a[i] > part){
        ans++;
      }
    }
    cout<<ans<<endl;
  }
	return 0;
}

