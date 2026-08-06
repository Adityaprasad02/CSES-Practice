#include<bits/stdc++.h>
using namespace std ; 

int n ,  bud ; 
vector<int> pr , pg ; 

vector<vector<int>> dp ; 

int solve ( int i , int bud ) {
     if(bud==0) return 0 ; 

     if(i==n) return -1 ; 

     if(dp[i][bud] != -2 ) return dp[i][bud]  ; 

     int take = 0 ; 
     if(pr[i]<=bud){
          take = solve(i+1 , bud - pr[i]) ; 

          if(take > -1 ){
            take = pg[i] + take ; 
          }
     }
https://www.geeksforgeeks.org/batch/placement-prep-training-skit
    int  nt = solve ( i + 1 , bud ) ; 

    return dp[i][bud] = max(take , nt ) ; 
}
int main () {
  cin>>n>>bud ; 

  pr.resize( n ) ; 
  pg.resize( n ) ;

  dp.resize( n , vector<int>(bud+1 , -1 )) ; 

  for(int i  = 0 ; i<n ; i++){
      cin>>pr[i] ; 
  }
   for(int i  = 0 ; i<n ; i++){
      cin>>pg[i] ; 
  }
   
//   int res = solve ( 0 , bud) ; 

//   cout<<res ; 

for(int i = 0 ; i<n ; i++) dp[i][0] = 0 ; 

for(int i = n-1 ; i>=0 ; i--){
    for(int j = 1 ; j<=bud ; j++){
        
     int take = 0 ; 
     if(pr[i]<=j){
         if(i<n-1) take = dp[i+1][j - pr[i]] ; 

          if(take > -1 ){
            take = pg[i] + take ; 
          }
     }

    int  nt = 0 ; 
    if(i+1 <= n-1 ) nt = dp[i + 1][j] ; 

      dp[i][j] = max(take , nt ) ;
    }
}

cout<<dp[0][bud] ; 

    return 0 ; 
}