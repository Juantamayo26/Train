#include <iostream>

using namespace std;
#define ll long long

int main(){
  double t;
  cin>>t;
  double low = 1, high = 1e9;
//  while(low <= high){
  for(int i=0; i<100; i++){
    double mid = low + (high-low)/2;
    if(mid*mid<=t){
      low = mid;
    }else{
      high = mid;
    }
  }
  cout<<high<<endl;
  return 0;
}
