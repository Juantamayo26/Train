#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
vector<pii>a;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, x;
  cin>>n>>x;
  for(int i=1; i<=n; i++){
    int aux;cin>>aux;
    a.push_back(make_pair(aux,i));
  }
  sort(a.begin(), a.end());
  int i=0, j=n-1;
  while(i<j){
    if(a[i].first+a[j].first==x){
      cout<<a[i].second<<" "<<a[j].second<<endl;
      return 0;
    }
    if(a[i].first+a[j].first>x){
      j--;
    }else{
      i++;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}

