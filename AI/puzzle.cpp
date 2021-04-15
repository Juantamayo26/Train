#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(3, vector<int>(3));
vector<vector<int>> E(3, vector<int>(3));
set<vector<vector<int>>>dp; 
map<vector<vector<int>>, vector<vector<int>>> F;
int dx[4] = {0, -1, 1, 0}; 
int dy[4] = {-1, 0, 0, 1}; 

pair<int, int> zero(vector<vector<int>> &G){
  for(int i=0;i<3; i++){
    for(int j=0; j<3; j++){
      if(G[i][j] == 0){
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

void printG(vector<vector<int>> &G){
  cout<<"==================="<<endl;
  for(int i=0;i<3; i++){
    for(int j=0; j<3; j++){
      cout<<G[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"==================="<<endl;
}

void GF(vector<vector<int>> G){
  if(F[G] == G){
    return;
  }
  GF(F[G]);
  printG(G);
}

//bandera
int DFS(vector<vector<int>> G){
  dp.insert(G); //visited
  if(G == E){
    GF(G);
    return 0;
  }
  pair<int, int> cur_zero = zero(G);
  for(int i=0;i<4; i++){
    int r = cur_zero.first+dy[i];
    int c = cur_zero.second+dx[i];
    if(r >= 0 && r<3 && c>=0 && c<3){
      vector<vector<int>> aux = G;
      aux[cur_zero.first][cur_zero.second] = aux[r][c];
      aux[r][c] = 0;
      if(dp.find(aux) == dp.end()){
        F[aux] = G;
        int ok = DFS(aux);
        if(!ok) return 0;
      }
    }
  }
  return 1;
}

void BFS(vector<vector<int>> G){
  queue<vector<vector<int>>>q;
  vector<vector<int>> aux(3, vector<int>(3));
  q.push(G);
  dp.insert(G);
  int iter = 0;
  pair<int, int> cur_zero;
  while(q.size()){
    G = q.front();
    aux = G;
    q.pop();
    cur_zero = zero(G);
    for(int i=0; i<4; i++){
      int r = cur_zero.first+dy[i];
      int c = cur_zero.second+dx[i];
      if(r >= 0 && r<3 && c>=0 && c<3){
        //cout<<r<<" "<<c<<endl;
        G[cur_zero.first][cur_zero.second] = G[r][c];
        G[r][c] = 0;
        if(dp.find(G) == dp.end()){
          F[G] = aux;
          iter++;
          //printG(G, iter);
          q.push(G);
          dp.insert(G);
        }
        if(G == E){
          GF(G);
        //  while(F[G] != G){
        //    printG(G);
        //    G = F[G];
        //  }
        //  printG(G);
          return;
        }
        G[r][c] = G[cur_zero.first][cur_zero.second];
        G[cur_zero.first][cur_zero.second] = 0;
      }
    }
  }
}

int main(){
  for(int i=0;i<3; i++){
    for(int j=0;j<3; j++){
      cin>>G[i][j];
    }
  }
  F[G] = G;
//  for(int i=0;i<3; i++){
//    for(int j=0; j<3; j++){
//      E[i][j] = i*3+j+1;
//    }
//  }
//  E[2][2] = 0;
  for(int i=0;i<3; i++){
    for(int j=0; j<3; j++){
      E[i][j] = i*3+j; 
    }
  }
  cout<<"1- BFS"<<endl;
  cout<<"2- DFS"<<endl;
  int opc;
  cin>>opc;
  if(opc==1){
    BFS(G);
  }else{
    DFS(G);
  }
  return 0;
}
