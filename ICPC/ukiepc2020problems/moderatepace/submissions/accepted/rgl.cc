#include <bits/stdc++.h>
using namespace std;

int median(int a,int b,int c){
  return a<=b and a<=c? min(b,c): b<=a and b<=c? min(a,c): min(a,b);
}

int main(){
  int n; cin>>n;
  vector<int> v[3]={vector<int>(n),vector<int>(n),vector<int>(n)};
  for (auto &i: v)
    for (auto &j: i)
      cin>>j;
  for (int i=0; i<n; i++)
    cout<<(i?" ":"")<<median(v[0][i],v[1][i],v[2][i]);
  cout<<endl;
}
