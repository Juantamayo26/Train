#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

vector < vector<int> > v(20001);
int us[20001];
int ans[20001][2];

int main(){
  //ios::sync_with_stdio(0); cin.tie(0); 
  int n, i,j;
  cin>>n;
  for(int x=1; x<n; x++){ //n-1
    cin>>i>>j;
    v[i].push_back(j);
    v[j].push_back(i);
  }
  queue<int> e;
  e.push(1);
  int aux=1;
  us[1]=1;
  if(n==2){
      ans[1][0] = 1;
      ans[1][1] = 2;
      ans[2][0] = 1;
      ans[2][1] = 2;
  }else{
    while(!e.empty()){
      int act = e.front();
      e.pop();
      for(auto i : v[act]){
        if(!us[i]){
          e.push(i);
          us[i]=1;
          if(ans[act][0]==0){
            ans[i][0]=aux;
            ans[act][0]=aux;
            aux++;
          }else if(ans[act][1]==0){
            ans[i][0]=aux;
            ans[act][1]=aux;
            aux++;
          }else
            ans[i][0]=ans[act][0];
        }
      }
    }
  }

  for(int i=1; i<=n; i++){
    if(ans[i][1]==0){
      ans[i][1]=aux;
      aux++;
      cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    }else if(ans[i][0]==0){
      ans[i][0]=aux;
      aux++;
      cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    }
    else
      cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
  }
}
