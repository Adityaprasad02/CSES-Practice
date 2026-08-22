#include<bits/stdc++.h>
using namespace std ; 

int n ; 
const int mod   = 1e9 + 7 ; 

// IF WE TAKE OUR IDX TILL N ->-> we will double count the pairs and modular division will become hectic since i 
                                 // havent studied modular arithmetic yet 

// EASY ->-> will do the iteration till n-1 and try to put n in 2nd set                                  


int fn ( int i , int t , vector<vector<int>> &dp ){
     if(t==0) return 1 ; 

     if( i==n ) return -1 ; 
   
     if(dp[i][t]!=-2) return dp[i][t] ; 

     int take = -1 ; 

     if(i<=t){
        take = fn ( i + 1 , t - i  , dp) ; 
     }

     int notake = fn ( i + 1 , t , dp) ; 

     int res =  0 ; 

     if(take != -1 ) res = ( res + take ) % mod  ; 
     if(notake != -1 ) res = ( res + notake) % mod  ;  


     return dp[i][t] =  (res >= 0 ) ? res : -1 ; 
}


int main () {

    cin>>n ; 

    int tot = (n * (n+1))/2 ; 

    if(tot%2!=0) {
              cout<<0 ; 

              return 0 ;
     }  ; 

    int target = tot/2 ; 

    vector<vector<int>> dp ( n+1 , vector<int> ( target + 1 , -2 )) ;  


   int outcome  =  fn ( 1 , target  , dp )  ;
   
   cout<<outcome ; 
     return 0 ; 
}