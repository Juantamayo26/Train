#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e5+10;
ll parent[maxi];
ll size[maxi];
ll cont;
ll ans;
ll find(ll x) {
  if(x==parent[x]){
    return x;
  }
  return parent[x] = find(parent[x]);
}

void union_sets(ll a, ll b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (size[a] < size[b])
      swap(a, b);
   // ans = ans-((size[a]*size[a])+(size[b]*size[b]));
    parent[b] = a;
    size[a] += size[b];
    cont--;
    ans = ans+(size[a]*size[a]);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n, m;
  cin>>n>>m;
  cont = n;
  ans = n;
  //make set
  for(int i=1;i<=n;i++){
    parent[i] = i;
    size[i] = 1;
  }
  for(int i=0;i<m;i++){
    ll aux;
    cin>>aux;
    if(aux==1){
      ll u, v;
      cin>>u>>v;
      union_sets(u, v);
    }else{
      ll div = __gcd(ans, cont);
      ll aux2 = ans/div;
      ll aux = cont/div;
      cout<<aux2<<"/"<<aux<<endl;
    }
  }
  
  return 0;
}

