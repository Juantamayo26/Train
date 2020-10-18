#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
int a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m; 
  cin>>n>>m;
  unordered_map<int,int>s;
  for(int i=0;i <n; i++){
    cin>>a[i];
  }
  for(int i=0; i<n;i++){
    int ai=a[i];
    if(s.count(m-a[i])){
      //cout<<i+1<<" "<<s.count(m-a[i])+1<<endl;
      cout<<i+1<<" "<<s[m-a[i]]+1<<endl;
      return 0;
    }else{
      s[a[i]]=i;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
  
}

