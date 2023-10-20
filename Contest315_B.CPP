#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using ll = long long;


int main() {
    
    ll m; cin >> m;
    vector<int> v1(m) , pref(m+1 , 0);
    for(int i = 0 ; i < m ; i++){
        cin >> v1[i];
        pref[i+1]= pref[i]+v1[i];
    }
    
    double midDay = (double)pref[m]/2.0;
    int pos = upper_bound(pref.begin() ,
    pref.end() , midDay) - pref.begin();
    
    int midMonth = pos;
    int Day = ceil(midDay - pref[pos-1]);
   
   cout << midMonth << " " << Day << endl;
    return 0;
}
