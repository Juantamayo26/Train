#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int16_t v=0,w;
  while (n--) cin>>w, (v+=(w%3))%=3;
  cout<<(v?"no":"yes")<<endl;
}
