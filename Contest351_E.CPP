#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using ll = long long;
 
 void dfs(int st,  vector<vector<int>>& books, vector<int>& vis){
  
  if(vis[st] == 1) 
        return;
 
  
  vis[st] = 1;

  int c = books[st][0];
  
    for(int i = 1 ; i <= c ; i++){
        if(!vis[books[st][i]]){
           dfs(books[st][i] , books , vis);
        }
    }

   if(st != 1)
    cout << st << " ";
 }
 
int main() {
    
     int n; cin >> n;
     
 vector<vector<int>> books(n+1);
 vector<int> vis(n+1 , 0);
  

   books[0] = {-1};
   for(int i = 1 ; i <= n ; i++){
   
     vector<int> v2;
     int c;  cin >> c;
     
     v2.push_back(c);
     
     for(int j=1 ; j <= c ; j++){
        int p; cin >> p;
        v2.push_back(p);
     }
     
     books[i] = v2;
   }


   dfs(1 ,  books , vis);
 
    return 0;
}
