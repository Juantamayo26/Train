#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string n;
  cin>>n;
  n=n+"ACGT";
  int cont=0;
  map<char, int>s;
  s['A']=0;
  s['C']=0;
  s['G']=0;
  s['T']=0;
  for(int i=0;i<n.length(); i++){
    s[n[i]]++;
    if(s[n[i]]==1){
      cont++;
    }
    if(cont==4){
      cout<<n[i];
      cont=0;
      s['A']=s['C']=s['G']=s['T']=0;
    }
  }
}
