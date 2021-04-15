#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int clamp(int x,int a,int b){return max(a,min(x,b));}

int main(){
  int w,n; cin>>w>>n;
  vector<pair<int,int>> x(n);
  for (auto &i: x) cin>>i.first;
  for (auto &i: x) cin>>i.second, i.second-=i.first;

  vector<int> p(n+1);
  p[0]=-x[0].second;
  for (int i=0; i<n; i++) p[i+1]=p[i]+x[i].second;
  int least=*min_element(p.begin(),p.end());
  for (auto &i: p) i-=least;

  auto cost=accumulate(p.begin(),p.end(),0);

  for (int i=0; i<=n; i=max(0,i)){
    int can=clamp(
      i==0? x[i].first-1-1 :
      i==n? w-x[i-1].first-1 :
            (x[i].first-x[i-1].first-2)/2, 0, p[i]);

    if (can){
      if (i>0) x[i-1].first+=can, x[i-1].second-=can;
      if (i<n) x[i].first-=can, x[i].second+=can;
      p[i]-=can;
      --i;
    }else{
      ++i;
    }
  }

  if (not accumulate(p.begin(),p.end(),0))
    cout<<cost<<endl;
  else
    cout<<"impossible"<<endl;
}
