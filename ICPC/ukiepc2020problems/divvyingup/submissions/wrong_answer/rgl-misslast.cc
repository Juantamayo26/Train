#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int64_t v=0,w;
  while (n-->1) cin>>w, v^=(w&1);
  cout<<(v?"no":"yes")<<endl;
}
