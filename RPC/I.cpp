#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
vector<pair<int, int>>s;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  int xmin=0, ymin=0;
  int xmax=1e9, ymax=1e9;
  for(int i=0; i<n;i++){
    int a, b;
    cin>>a>>b;
    s.push_back({a,b});
    xmax = min(xmax, a);
    ymax = min(ymax, b);
    xmin = max(xmin, a);
    ymin = max(ymin, b);
  }
  int area = 2*(abs(xmax - xmin)+abs(ymax - ymin));
  ll per=0;
  for(int i=1; i<n; i++){
    per+= abs((s[i].second-s[i-1].second))+abs((s[i].first-s[i-1].first));
  }
  per+= abs((s[0].second-s[n-1].second))+abs((s[0].first-s[n-1].first));
  cout<<abs(area-per)<<endl;
  
}

