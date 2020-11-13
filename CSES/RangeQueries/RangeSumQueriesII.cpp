#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
ll a[maxi];
ll st[4*maxi];

void build(int pos, int b, int e){
  if(b==e){
    st[pos] = a[b];
  }else{
    int mid = (b+e)/2;
    build(2*pos, b, mid);
    build(2*pos+1, mid+1, e);
    st[pos] = st[pos*2] + st[pos*2+1];
  }
}

void update(int pos, int b, int e, int pv, int val){
  if(e<pv||pv<b){
    return;
  }
  if(b==e){
    st[pos] = val;
  }else{
    int mid = (b+e)/2;
    update(pos*2, b, mid, pv, val);
    update(pos*2+1, mid+1, e, pv, val);
    st[pos] = st[pos*2] + st[pos*2+1];
  }
}

ll query(int pos, int b, int e, int l, int r){
  if(e<l || r<b){
    return 0;
  }
  if(b>=l && r>=e){
    return st[pos];
  }
  int mid = (b+e)/2;
  return (query(2*pos, b, mid, l, r) + query(2*pos+1, mid+1, e,l, r));
}

int main(){
 ios::sync_with_stdio(0); cin.tie(0); 
  int n, q;
  cin>>n>>q;
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }
  build(1, 1, n);
  while(q--){
    int a, b, c;
    cin>>a>>b>>c;
    if(a==1){
      update(1, 1, n, b, c);
    }else{
      cout<<query(1, 1, n, b, c)<<endl;
    }
  }
  return 0;
}

