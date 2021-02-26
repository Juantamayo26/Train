#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
//  map<int, int, greater<int>> f; //> to <
//  map<int, int, less<int>> f; //< to >
  map<int, int> f; //< to >
  f[1] = 21;
  f[2] = 31;
  f[0] = 1;
  f.insert(make_pair(123, 290));
  f.insert({4, 40});

  cout<<f[1]<<endl;
//  cout<<f[3]<<endl;

  for(auto i=f.begin();i!=f.end(); i++){
    cout<<i->first<<" "<<i->second<<endl;
  }
  //otra
  cout<<endl;
  for(auto &i1: f)
    cout<<i1.first<<" "<<i1.second<<endl;


  ///////// ////+/////////
  //mymap.clear();
//  map<int, vector<int>> s;
//  s[0].push_back(13);
//  s[0].push_back(50);
//  s[0].push_back(100);
//  cout<<s[0].front()<<endl;
//  cout<<s[0].back()<<endl;
//  cout<<endl;
//  for(auto &i1: s){
//    cout<<i1.first<<endl;
//    for(auto &i2: i1.second)
//      cout<<i2<<" ";
//    cout<<endl;
//  }
}

//     .begin()  --> return iterator
//    auto var  = person.begin();
//    cout<<"By var iterator  " <<var->first <<" "<<var->second<<endl;
//    
//     .end()  --> return iterator
//    auto var  = person.end();   // Not actual map
//    cout<<"By var iterator  " <<var->first <<" "<<var->second<<endl;
//    
//    cout<<person.size()<<endl;
//    cout<<person.max_size()<<endl;
//    
//     .erase()
//    
//     .empty()  -->whether map is empty or not
//     0 --> map is not empty
//     1 --> map is empty
//    
//    
//    person.clear();   // delete all the values in map
//    cout<<"map is empty or not ?  "<<person.empty()<<endl;
    


