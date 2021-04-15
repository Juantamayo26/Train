#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int64_t v=0,w;
  while (n--) cin>>w, v|=(w%3!=0);
  cout<<(v?"no":"yes")<<endl;
}
