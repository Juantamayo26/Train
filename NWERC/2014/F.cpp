#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int maxi = 1e5;
vector< pair< int, int> > s(maxi);

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);
  int n, p, x, y;
  int ans = 0;
  
  cin>>n;
  std::uniform_int_distribution<int> distribution(0,n-1);
  cin>>p;
  for(int i=0; i<n; i++){
    cin>>x>>y;
   //s.push_back({x,y});
     s[i] = (make_pair(x,y));
  }
  for(int i=0; i<250; i++){
    ans=0;
    int p1 = distribution(generator);
    int p2 = distribution(generator);
    while(p1==p2&&n!=1)
      p2 = distribution(generator);
    ll linex = s[p2].first - s[p1].first;
    ll liney = s[p2].second - s[p1].second;
    for(int j=0; j<n; j++){
      ll lpx = s[j].first - s[p1].first;
      ll lpy = s[j].second - s[p1].second;
//      cout<<s[j].first<<" "<<s[j].second<<endl;
      if((linex*lpy - lpx*liney)==0){
        ans++;
 //       cout<<ans<<" "<<j<<" "<<i<<endl;
      }
    }
    if(ans*100 >= n*p)
      break;
  }
  if(ans*100 >= n*p)
    cout<<"possible"<<endl;
  else
    cout<<"impossible"<<endl;
}

