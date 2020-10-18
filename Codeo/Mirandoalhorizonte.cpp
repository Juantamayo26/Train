#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 500100;
int a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  for(int i=1; i<=t; i++){
    int n;
    cin>>n;
    for(int j=0; j<n; j++){
      cin>>a[j];
    } 
    stack<int>s;
    vector<int>ans(n);
    s.push(0);
    cout<<"Case #"<<i<<": ";
    for(int j=0; j<n; j++){
      while(!s.empty() && a[j]>a[s.top()]){
        ans[s.top()]=a[j];
        s.pop();
      }
      s.push(j);
    }
    for(auto i: ans){
      if(i==0)
        cout<<-1<<" ";
      else
        cout<<i<<" ";
    }
    cout<<endl;
  }
}

