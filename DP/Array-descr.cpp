#include<bits/stdc++.h> 
using namespace std ; 
int n , m ; 

vector<int> num  ; 

const int mod = 1e9 + 7; 

vector<vector<int>> dp ; 


int solve ( int crrIdx , int prevVal ){

    if(crrIdx==n){

        return 1 ; 
    }
    
    if(dp[crrIdx][prevVal]!=-1 ) return dp[crrIdx][prevVal] ; 

    
    int no = num[crrIdx] ; 
    
    int arrs = 0 ; 

    if(crrIdx > 0 ){

          

           if(no!=0){
               int diff = abs (no - prevVal) ;

               if( diff <= 1 ) arrs = ( arrs + solve ( crrIdx + 1 , no ) ) % mod  ;

           }else if( no==0 ){
               
                 for( int a = -1 ; a<=1 ; a++ ){
                     int new_no = prevVal  + a ; 
                     if(new_no>=1 && new_no<=m ){
                          arrs  = (arrs +  solve ( crrIdx + 1 , new_no ))%mod ; 
                     }
                 }
           }
         
       } else if( crrIdx==0 ){
            
         if(no==0){
             for(int i = 1 ; i<=m ; i++ ){
                
                 arrs = (arrs +  solve( crrIdx +1 , i ))%mod ; 
                 
             }
         }else if(no>0){
               arrs =  (arrs +  solve ( crrIdx + 1 , no ))%mod ;
               
         }
       }

       return dp[crrIdx][prevVal] = arrs ; 
} 
int main () {
   
    cin>>n>>m ; 

    num.resize(n) ; 

    dp.resize(n , vector<int>(m+1 , -1)) ; 

    for(int i = 0 ; i<n; i++){
        cin>>num[i] ; 
    }
    int ans = solve ( 0 , 0 ) ; 

    cout<<ans ;
    return 0 ; 
}