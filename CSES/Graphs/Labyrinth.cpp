#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 1200;
vector<vector<char>>s(maxi);
int seen[maxi][maxi];
string mov = "RLDU";
int mi[]={0,0,1,-1};
int mj[]={1,-1,0,0};
int fat[maxi][maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  pair<int, int> in;
  for(int i=0;i<n;i++){
    for(int j=0; j<m; j++){
      char aux; cin>>aux;
      s[i].push_back(aux);
      if(aux=='A'){
        in = make_pair(i,j);
      }
    }
  }
  queue<pair<int, int>>q;
  q.push(in);
  seen[in.first][in.second]=1;
  int i, j;
  memset(fat, -1, sizeof(fat));
  while(!q.empty()){
    i = q.front().first;
    j = q.front().second;
    q.pop();
    if(s[i][j]=='B'){
      break;
    }
    for(int k=0;k<4; k++){
      int ni = i+mi[k];
      int nj = j+mj[k];
      if(ni>=n || nj >= m || ni<0 || nj<0){
        continue;
      }
      if(s[ni][nj]!='#'&&!seen[ni][nj]){
        seen[ni][nj]=1;
        q.push(make_pair(ni, nj));
        fat[ni][nj]=k;
        //cout<<mov[fat[ni][nj]]<<" ";
      }
    }
  }
  if(s[i][j]!='B'){
    cout<<"NO"<<endl;
    return 0;
  }
  vector<char>ans;
  cout<<"YES"<<endl;
  while(fat[i][j]!=-1){
    ans.push_back(mov[fat[i][j]]);
    //cout<<fat[i][j]<<endl;
    int k=fat[i][j];
    //i = i-(mi[fat[i][j]]);
    //j = j-(mj[fat[i][j]]);
    i = i-(mi[k]);
    j = j-(mj[k]);
  }
  reverse(ans.begin(), ans.end());
  cout<<ans.size()<<endl;
  for(char i: ans){
    cout<<i;
  }
  cout<<endl;
}
