#include<bits/stdc++.h>
using namespace std ; 



vector<int> coins ;

vector<vector<int>> dp ; 

int minCoins( int idx , int target ){
    

    if(target==0){
        return 0 ; 
    }

    if(idx==coins.size() || target < 0 ){
        return 1e9 ;
    }

    if(dp[idx][target]!=-1) return dp[idx][target] ; 


    int take = 1e9  ;
    if(coins[idx] > 0 ){ 
          take =  minCoins( idx , target - coins[idx] ) ; 

         if(take!=1e9){
            take += 1 ; 
         }
        }

     int notTake = minCoins(idx + 1 , target ) ; 

     return dp[idx][target] = min(take,notTake) ; 
}

vector<int>dp2 ; 
int solve ( int target ){
    if(target==0) return 0 ; 

    if(dp2[target]!=-2) return dp2[target] ; 

    int ans = 1e9 ; 

    for(int i = 0 ; i<coins.size() ; i++){


         if(coins[i]<=target){
            int res = solve ( target - coins[i]) ; 
            if(res!=-1) {
                ans = min(ans , 1+res) ; 
            }
         }
    }

    return dp2[target] = ans == 1e9 ? -1 : ans  ; 
}

int main () {
   int n , target ; 
   cin>>n>>target ; 

   dp.assign( n , vector<int>(  target + 1 , 1e9  )) ; 

   dp2.assign( target+1 , -2 ) ;  

   for(int i = 0 ; i<n ; i++ ){
     int vl ; 
     cin>>vl ; 
    coins.push_back(vl) ; 
   }

   
   // int res = minCoins( 0 , x )   ; // this is top-down memo 

   // int only single parameter ; 
    // int ans = solve ( target ) ; 

    // cout<<ans ; 
   
    // bottom up 

    for(int i = 0 ; i<n ; i++ ) dp[i][0] = 0 ; 

    for(int idx = n-1 ; idx >= 0 ; idx-- ){
        for(int t = 1 ; t<=target ; t++){

            int res1 = 1e9 ; 
            if( (t  - coins[idx] )  >=0 ) res1 =  dp[idx][t - coins[idx]] ; 

            if(res1!=1e9) {
                 res1 += 1 ; 
            }

            int res2 = 1e9 ; 
            if(idx<n-1) res2 = dp[idx+1][t] ; 

            dp[idx][t] = min( res1 , res2 ) ; 
        }
    }

    cout<< ( (dp[0][target]==1e9) ? -1 : dp[0][target] ) ; 

    return 0 ; 
}
