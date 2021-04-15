#include <bits/stdc++.h>
using namespace std;

auto get(int n){
  vector<int> res(n);
  for (auto &i: res){
    int steps;
    char dirn;
    scanf(" %c",&dirn);
    if (dirn=='?') continue;
    scanf(" %d",&steps);
    i=steps*4+(dirn=='n'?0:dirn=='e'?1:dirn=='s'?2:3);
  }
  return res;
}

int main(){
  int n1,n2; scanf("%d%d",&n1,&n2);
  auto const a=get(n1),b=get(n2);
  int res=0;

  for (int i=0; i<=n1-n2; i++){
    int cost=0;
    for (int j=0; j<n2; j++) cost+=(a[i+j]==0)*(b[j]==0);
    for (int j=0; j<n2; j++) cost+=(a[i+j]!=0)*(b[j]!=0);
    for (int j=0; j<n2; j++) cost-=(a[i+j]==b[j]);
    if (cost==0){
      ++res;
    }
  }
  cout<<res<<endl;
}
