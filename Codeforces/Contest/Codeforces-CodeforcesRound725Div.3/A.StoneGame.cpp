// time-limit: 2000
// problem-url: https://codeforces.com/contest/1538/problem/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'
const int oo = 110;
int a[oo];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    for(int i=0; i<n; i++){
      cin>>a[i];
    }
    int index1 = 0;
    int index2 = 0;
    for(int i=0; i<n; i++){
      if(a[i] < a[index1]){
        index1 = i;
      }
      if(a[i] > a[index2]){
        index2 = i;
      }
    }
    int mini = min(index1, index2);
    int maxi = max(index1, index2);
    int ans1 = maxi+1;
    int ans2 = n-mini;
    int ans3 = mini+1 + n-maxi;
    cout<<min({ans1, ans2, ans3})<<endl;
  }
	return 0;
}

