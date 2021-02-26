#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int maxi = 2e5;
int st[4*maxi];
int x[maxi];

void build(int pos, int b, int e){
  if(b==e)
    st[pos] = x[b];
  else{
    int mid = (b+e)/2;
    build(pos*2, b, mid);
    build(pos*2+1, mid+1, e);
    st[pos] = st[pos*2] + st[pos*2+1];
  }
}  

void update(int pos, int b, int e, int pv, int val){
  if(pv<b || e<pv)
    return;
  if(b==e)
    return st[pos] = val;
  update(pos*2, b, mid);
  update(pos*2+1, mid+1, e);
  st[pos] = st[pos*2] + st[pos*2+1];
}


int query(int pos, int b, int e, int l, int r){
  if(e<l || r<b)
    return 0;
  if(e<=r && l<=b)
    return st[pos];
  int mid = (b+e)/2;
  return query(pos*2, b, mid, l,r )+query(pos*2+1, mid+1, b,l,r);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>x[i];
  build(1, 0, n-1);
  cout<<query(1,1,n,1,n)<<endl;
}

