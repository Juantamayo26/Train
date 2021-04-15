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

  __int128 rolling_hash=0;
  __int128 factor=1;
  for (int i=0; i<n2; i++){
    factor*=271ll;
    rolling_hash*=271ll;
    rolling_hash+=a[i];
  }

  map<__int128,int> seen;
  for (int i=0; i<=n1-n2; i++){
    int cost=0;
    if (seen.count(rolling_hash)){
      cost=seen[rolling_hash];
    }else{
      for (int j=0; j<n2; j++) cost+=(a[i+j]==0)*(b[j]==0);
      for (int j=0; j<n2; j++) cost+=(a[i+j]!=0)*(b[j]!=0);
      for (int j=0; j<n2; j++) cost-=(a[i+j]==b[j]);
      seen[rolling_hash]=cost;
    }
    if (cost==0){
      ++res;
    }

    rolling_hash*=271ll;
    rolling_hash-=factor*a[i];
    if (i+n2<n1) rolling_hash+=a[i+n2];
  }
  cout<<res<<endl;
}
