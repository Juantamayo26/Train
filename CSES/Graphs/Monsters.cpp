#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1010;
const int oo = 1e9;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
string mov = "DURL";
char a[maxi][maxi];
vector<vector<int>>vis(maxi, vector<int>(maxi, oo));
vector<vector<int>>A(maxi, vector<int>(maxi, oo));
int father[maxi][maxi];
int main(){
 ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  pii in;
  queue<pii>q;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
      if(a[i][j] == 'A'){
        in = make_pair(i, j);
      }
      if(a[i][j] == 'M'){
        q.push(make_pair(i,j));
        vis[i][j] = 0;
      }
    }
  }
  while(!q.empty()){
    int u = q.front().first;
    int v = q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int x = u+di[i];
      int y = v+dj[i];
      if(x>=n || y>=m || x<0 || y<0){
        continue;
      }
      if(a[x][y]!='#'&&vis[u][v]+1<vis[x][y]){
        vis[x][y] = vis[u][v]+1;
        q.push(pii(x,y));
      }
    }
  }
  q.push(in);
  vector<char>ans;
  A[in.first][in.second] = 0;
  memset(father, -1, sizeof(father));
  int u, v;
  bool ansa=true;
  while(!q.empty()){
    u = q.front().first;
    v = q.front().second;
    q.pop();
    if(u==n-1 || v==m-1 || u==0 || v==0){
      ansa=false;
      break;
    }
    for(int i=0; i<4; i++){
      int x = u+di[i];
      int y = v+dj[i];
      if(x>=n || y>=m || x<0 || y<0){
        continue;
      }
      if((A[u][v]+1 < vis[x][y])&&a[x][y]!='#'&&A[u][v]+1 < A[x][y]){
        father[x][y] = i;
        A[x][y] = A[u][v] + 1;
        q.push(pii(x,y));
      }
    }
  }
  if(ansa){
    cout<<"NO"<<endl;
    return 0;
  }
  while(father[u][v]!=-1){
    ans.push_back(mov[father[u][v]]);
    int aux=father[u][v];
    int k=father[u][v];
    u = u-(di[k]);
    v = v-(dj[k]);
  }
  cout<<"YES"<<endl;
  cout<<ans.size()<<endl;;
  reverse(ans.begin(), ans.end());
  for(auto i: ans){
    cout<<i;  
  }
  cout<<endl;
  return 0;
}
