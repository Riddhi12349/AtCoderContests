#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using ll = long long;

int main() {
    
   ll n; cin >> n;
 
   vector<pair<ll,ll> > v1(n);
   for(int i = 0;i < n ; i++){
       int f , d; 
       cin >> f >> d;   v1[i] = {d , f};
   }
   
   sort(v1.begin() , v1.end());
   ll s;
   
   if(v1[n-1].second != v1[n-2].second){
         s = v1[n-1].first + v1[n-2].first;
   }
  else{
    s = v1[n-1].first + (v1[n-2].first/2);
    
    for(int t = n-2 ; t >= 0 ; t--){
           if(v1[t].second == v1[n-1].second){
               continue;
           }
           else{
               s = max(s , (v1[n-1].first + v1[t].first));
           }
       }
   }
   
   cout << s << endl;

    return 0;
}
