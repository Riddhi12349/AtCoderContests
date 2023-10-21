#include <iostream>
using namespace std;
using ll = long long;
#include <vector>
#include <cmath>
#include <algorithm>

 
int main(){
  
   ll n , d , p;
   cin >> n >> d >> p;
   ll a[200000];
   
   ll tot= 0;
   for(int i = 0 ; i < n ; i++){
       cin >> a[i];
       tot+= a[i];
   }
   
   sort(a , a+n , greater<ll>());
  // A = [7,6,6,3,2,1],d=2,tot=25
  
   for(int i = 0 ; i < n  ; ){
     ll sum = 0;
       for(int j = 0 ; j < d ; j++){ //making group of d items
           if(i+j >= n) break;
           sum += a[i+j];
       }
      if(sum > p){
          tot -= sum;
          tot += p;
          i += d;
      }else{
          break;
      }
   }
   
    cout << tot << endl;
  
 return 0;
}
