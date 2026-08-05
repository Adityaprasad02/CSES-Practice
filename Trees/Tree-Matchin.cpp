#include<bits/stdc++.h>
using namespace std ; 
int n  ; 
vector<vector<int>> t , dp ;


void solve ( int nd , int par ){
     

     for( auto it : t[nd] ){
         
          if(it!=par){
              
              solve( it , nd )  ; 
              
              auto cn = dp[it] ; 
              

             dp[nd][0] += max( cn[0] , cn[1]) ; 
          }
     }


     for( auto it : t[nd] ){
          
           if(it!=par){

             dp[nd][1] = max( dp[nd][1] , 1 + dp[it][0] + dp[nd][0] - max( dp[it][1] , dp[it][0] ) ) ; 
           }
     }
      
}




int main () {
    
    cin>>n  ; 
    t.resize( n ) ; 
    dp.resize( n , vector<int>( 2 , 0 )) ; 

    t[0].emplace_back(-1) ; 

    for(int i = 0 ; i<n-1 ; i++ ){
         int u, v ; 
         cin>>u>>v ; 
         
         t[u-1].emplace_back(v-1) ; 
         t[v-1].emplace_back(u-1) ; 


    }

    solve( 0 , -1  ) ;  

    cout<<max(dp[0][0] , dp[0][1]) ; 



    
    return 0 ; 
}
