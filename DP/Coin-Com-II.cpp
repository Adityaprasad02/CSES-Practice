#include<bits/stdc++.h>
using namespace std ; 



vector<int> coins ;

vector<vector<int>>dp ; 

const int mod = 1e9  +  7 ; 

int solve ( int target , int idx ){
    if(target==0) return 1 ; 

    if(idx==coins.size()) return 0 ; 

    if(dp[target][idx]!=-1) return dp[target][idx] ; 

    int sum = 0 ; 
   
    int take = 0  ; 
    if(coins[idx]<=target){
        take = solve( target - coins[idx] , idx) ;  
    }

    int notTake = solve(target , idx+1 ) ;  
    

    return dp[target][idx] = (take + notTake) % mod  ; 
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n , target ; 
   cin>>n>>target ; 

   set<int> st ;  // to remove the duplicates

   
   for(int i = 0 ; i<n ; i++ ){
       int vl ; 
       cin>>vl ; 
       st.insert(vl) ; 
    }
    
    for(auto it : st){
        coins.push_back(it) ; 
    }

    dp.assign( coins.size() ,vector<int>( target + 1 , 0 ) ) ;  
    
    int sz = coins.size() ; 
    // int ans = solve(target , 0) ; 
    // cout<<ans ; 

    // bottom up 

    
    for(int i = 0 ; i<sz ; i++) dp[i][0] = 1 ; 

   for(int i = sz-1 ; i>=0 ; i--){
    for(int t = 1 ; t<=target ; t++ ){
        
            int take = 0  ; 
            if(coins[i]<=t){
                take = dp[i][t - coins[i]] ;  
            }

            int notTake = 0 ;
            if(i<sz-1){
            notTake = dp[i+1][t] ;  
            }
            

             dp[i][t] = (take + notTake) % mod  ;
          }
    }

    int res = dp[0][target]  ; 

    cout<<res ; 
 




    return 0 ; 
}
