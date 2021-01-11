// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int oo = 1e9;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg; 
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    int ans =0;
    vector<int>a(n);
    for(int i=0; i<n;i++){
      cin>>a[i];
    }
    sort(a.begin(), a.end());
    for(int i=n-1;i>=0;i--){
      if(ans <= 0){
        ans+=a[i];
      }else{
        ans-=a[i];
      }
    }
    cout<<(ans==0?"YES":"NO")<<endl;
  }

  return 0;
}

