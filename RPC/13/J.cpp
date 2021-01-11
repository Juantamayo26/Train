#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.second < b.second; 
    } 
}; 

int main(){
//  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  priority_queue<pair<int, int>, myComp > s; 
  cin>>t;
  while(t--){
    int a,b,c;
    string name;
    cin>>a;
    if(a==1){
      cin>>b>>c>>name;
      s.push(make_pair(c, b));
    }else{
      pair<int, int> top = s.top(); 
      cin>>b;
      cout<<top.second<<" "<<b<<" "<<b-top.second<<" "<<"NAME\n";
      s.pop();
    }
  }
  
  return 0;
}

