#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
vector<int>estados = {3,3,0,0,0};
// La estructura es la siguiente:
// Es un vector de pares entonces se veria algo como esto:
// [numero de canibales isla0][numero de misioneros isla0][numero de canibales isla1][numero de canibales isla1][saber en que posicion esta el barco]
// 3 3 0 0 0 -> estado inicial
set<vector<int>>dp;
// Creo esta estructura

//    Movimientos
// 1. Mover un canibal al otro lado
// 2. Mover dos canibales al otro lado
// 3. Mover un misionero al otro lado
// 4. Mover dos misioneros al otro lado
// 5. Mover un misionero y un canibal al otro lado
vector<vector<int>>movs={{1, 1},{1,0}, {0, 1}, {2, 0}, {0, 2}};

// Estructura para reconstruir en camino
map<vector<int>, vector<int>>f;

//funcion para verificar si es valido el movimiento
bool verificar(vector<int> &aux){
  //verificar que no queden mas canibales que misioneros
  if(aux[1]>0 && aux[3]>0 && (aux[0] > aux[1] || aux[2] > aux[3])){
    return false;
  }
  //verificar que no queden negativos
  for(int i=0;i<=3; i++){
    if(aux[i]<0){
      return false;
    }
  }
  return true;
}

//verificar si ya todos estan todos en la 2 isla
bool fin_juego(vector<int> &aux){
  if(aux[2] == 3 && aux[3] == 3){
    return true;
  }
  return false;
}


void imprimir_solucion(vector<int> F){
  if(f[F] == F){
    return;
  }
  imprimir_solucion(f[F]);
  for(int i=0;i<=4; i++){
    cout<<F[i]<<"  ";
  }
  cout<<endl;
}

void BFS(vector<int> estados){
  queue<vector<int>>q;
  vector<int>aux;
  q.push(estados);
  dp.insert(estados);
  f[estados] = estados;
  while(q.size()){
    estados = q.front();
    q.pop();
    int islaDondeVoy = (estados[4]^1)*2;
    int islaDondeEstoy = (estados[4])*2;
    for(int i=0; i<=4; i++){
      aux = estados;
      aux[islaDondeVoy]+= movs[i][0];
      aux[islaDondeVoy+1]+= movs[i][1];
      aux[islaDondeEstoy]-= movs[i][0];
      aux[islaDondeEstoy+1]-= movs[i][1];
      aux[4] = aux[4]^1;
      if(verificar(aux) && dp.find(aux) == dp.end()){
        f[aux]= estados; 
        q.push(aux);
        dp.insert(aux);
      }
      if(fin_juego(aux)){
        cout<<"Solucion Encontrada"<<endl;
        imprimir_solucion(aux);
        return;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  //P significa donde esta el barco, en este caso isla 0 o isla 1
  cout<<"Estado Inicial"<<endl;
  cout<<"C0 M0 C1 M1 P"<<endl;
  cout<<"3  3  0  0  0"<<endl;
  BFS(estados);
	return 0;
}

