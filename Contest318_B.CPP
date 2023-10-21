#include <iostream>
using namespace std;
using ll = long long;
#include <vector>
#include <cmath>
#include <algorithm>

 
int main(){
 
 int n; cin >> n;
  vector<vector<int>> v1(n);
  
  int grid[102][102]= {0};
  
  for(int k = 0 ; k < n ; k++){
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    v1[k] = {a,b,c,d};
  }
  
  for(int k = 0 ; k < n ; k++){
      int a = v1[k][0],b=v1[k][1],c=v1[k][2],d=v1[k][3];
     for(int i = a ; i < b ; i++){
        for(int j = c ; j < d ; j++){
            grid[i][j] = 1;
        }
     }
  }
  

  int ans = 0;
  for(int i = 0 ; i <= 100 ; i++){
    for(int j = 0 ; j <= 100 ; j++){
       if(grid[i][j]==1) {
        ans++;
       }
    }
}

    cout << ans << endl;
  
 return 0;
}
