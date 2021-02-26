#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primera(vector<int> s){
  int iterator=s.size()-1;
  int current;
  do{
    current = s[iterator]+1;
    s[iterator]=current%10;
    iterator--;
  }while(current>=10 && iterator>=0);
  if(current>=10){
    s.insert(s.begin(), 1);
  }
  return s;
}

vector<int> segundo(vector<int> s, int x){
  int iterator = s.size()-1;
  int current;
  int aux = x;
  do{
    current = s[iterator]+aux;
    s[iterator] = current%10;
    aux = current/10;
    iterator--;
  }while(current >= 10 && iterator>=0);
  if(aux>0){
    s.insert(s.begin(), aux);
  }
  return s;
}

vector<int> tercero(vector<int> s1, vector<int> s2){
  vector<int> ans;
  int maxi = max(s1.size()-1, s2.size()-1);
  int current = 0;
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  for(int i=0;i<=maxi; i++){
    if(s1.size()-1 >= i){
      current+=s1[i];
    }
    if(s2.size()-1 >= i){
      current+=s2[i];
    }
    ans.push_back(current%10);
    current = current/10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

void impr(vector<int> s){
  for(int i=0; i<s.size(); i++){
    cout<<s[i]<<" ";
  }
  cout<<endl;
}

int main(){
  impr(primera({9,8,1}));
  impr(primera({1}));
  impr(primera({9,9,9}));
  impr(segundo({9,9,9}, 9));
  impr(segundo({3,9}, 2));
  impr(tercero({1,1, 9}, {1,1}));
  return 0;
}
