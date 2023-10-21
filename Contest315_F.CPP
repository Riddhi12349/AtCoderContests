#include <iostream>
using namespace std;
using ll = long long;
#include <vector>
#include <cmath>
#include <algorithm>

//here the crux of the qs is total-skipped points cannot exceed 30
//b/c we have tot x = 1e4 and tot y = 1e4
//max dist we can have is from (0,0) to (1e4,1e4) ; dist = 1e4
//i.e.for maximum penalty = (0+pow(2,c-1) = 1e4) => c = 30

double dp[100000][29][29];
vector<pair<int,int>> p;

double findDist(int i , int j){
 
//   i = i-1,j=j-1;
 
 double x1 = p[i].first , x2 = p[j].first, y1 = p[i].second , y2 = p[j].second;
 return sqrt((double)(x2-x1)*(x2-x1)*1.0 + (double)(y2-y1)*(y2-y1)*1.0);

 }

double find(int i , int cont_skipped , int tot_skipped ,  int n){
    
    int prv = i - cont_skipped-1;
    
    if(tot_skipped > 27) return 1e9;
    
    if(i == n){
        if(tot_skipped == 0){
             double dist = findDist(n , prv);
             return dist;
        }
        double d = findDist(n , prv)*1.0 + (1 << (tot_skipped-1))*1.0;
        return d;
    }
    

    if(dp[i][cont_skipped][tot_skipped] >= 0)
        return dp[i][cont_skipped][tot_skipped];
        
    double pick = findDist(i,prv) + find(i+1 , 0 , tot_skipped ,n );
    double notpick = find(i+1 , cont_skipped + 1 , tot_skipped + 1 ,n );

    return dp[i][cont_skipped][tot_skipped] = min(pick , notpick);
}
int main(){

    int n; cin >> n;
   p = vector<pair<int,int>>(n+1);
    p[0]={0,0};
    for(int i = 1 ; i <= n ; i++){
        int x , y;
        cin >> x >> y; p[i] = {x,y};
    }

    // 3d - dp contains - 3 coordinates (i,j,k)
    // i - indx on which we are 
    // j - indicates no of continous elemnts to be skipped , to find the prv indx , for finding distance
    // k - indicates tot no ofelements to be skipped
  
    for(int i = 0 ; i <= 1e4 ; i++){
        for(int j = 0 ; j < 30 ; j++){
            for(int k = 0 ; k < 30 ; k++){
                dp[i][j][k] = -1.0;
            }
        }
    }

   double d= find(2 , 0 ,  0 , n);  
//   double ans = sqrt(d);
   cout <<  d << endl;
    return 0;
}
