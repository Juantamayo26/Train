#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
ll a[maxi];
ll b[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n,m;
  cin>>n>>m;
  multiset<int>s;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    s.insert(-a);
  }
  sort(a, a+n);
  while(m--){
    int aux;
    cin>>aux;
    auto a = s.lower_bound(-aux);
    if(a == s.end()){
      cout<<-1<<endl;
    }else{
      cout<<*a*-1<<endl;
      s.erase(a);
    }
  }
}

