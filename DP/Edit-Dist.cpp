#include<bits/stdc++.h>
using namespace std ; 

string str , target ; 

vector<vector<int>> dp ;  
int fn ( int i , int j ){

    if(i<0 && j<0) return 0 ; // word transformed 

    if( i>=0 && j<0 ) return i+1 ; // word completed now have  to remove  i + 1 chars

    if( i<0 && j>=0 ) return j + 1  ; // not able to transform word 


    if(dp[i][j]!=-1) return dp[i][j] ; 

     int ans = 1e9 ; 
     int a = 1e9 , b = 1e9 , c = 1e9 ; 
        
         if(str[i]==target[j]){
            ans =  fn( i -1 , j-1 ) ; 
         }
         // replace opr
         a = 1 + fn( i-1 , j-1 ) ; 

         // add char
         b = 1 + fn( i , j - 1 ) ; 

         // removed a char ; 
        c = 1 + fn(i-1 , j ) ;
         
         ans  = min ( ans ,  min( a , min(b,c)) )   ; 
     

     return dp[i][j] = ans ; 
        
}
int main () { 

    cin>>str>>target ; 

    int n  = str.size() , m = target.size() ; 

    dp.assign( n , vector<int>( m , -1 )) ; 

    int res = fn ( n-1  , m-1  ) ; 
     cout<<res ; 

    return 0 ; 
}