#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int maxi = 2e5+8;
int st[4*maxi];
int x[maxi];

void build(int pos, int b, int e){
  if(b==e){
    st[pos] = x[b];
  }else{
    int mid = (b+e)/2;
    build(pos*2,b,mid);
    build(pos*2+1,mid+1,e);
    st[pos] = min(st[pos*2],st[pos*2+1]);
  }
}

int query(int pos, int b, int e, int l, int r){
  if(e<l || r<b)
    return 1e9;
  if(e<=r && l<=b)
    return st[pos];
  int mid = (b+e)/2;
  return min(query(pos*2, b, mid, l,r ),query(pos*2+1, mid+1, e,l,r));
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n, q;
  cin>>n>>q;
  for(int i=0; i<n; i++){
    cin>>x[i];
  }
  build(1, 0, n-1);
  while(q--){
    int a, b;
    cin>>a>>b;
    cout<<query(1,1,n,a,b)<<endl;
  }
}

