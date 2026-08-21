#include<bits/stdc++.h> 
using namespace std ; 


// ### G A M E - T H E O R Y ####

long long n ; 
vector<long long> arr ; 

vector<vector<long long>> dp ; 

long long fn ( long long i , long long  j ){

    if(i>j || j<=-1 || i>=n) return 0 ; 

     if(dp[i][j]!=1e14) return dp[i][j] ; 

    if(i==j) return dp[i][j] = arr[j] ; 

    long long r1 = fn(i+2 , j) , r2 = fn(i+1 , j-1) , r3 = fn(i , j-2) ; 
    
    long long min1 = min(r1 , r2) ; 
    
    long long choice1 = -1e14 ; 

     choice1 = arr[i] + min1 ;

     
    long long min2 = min(r2 , r3) ; 
    
    long long choice2 = -1e14 ; 

     choice2 =  arr[j] + min2 ;



    long long fin = max(choice1 , choice2) ; 


    if(fin==-1e14) return dp[i][j] = fin ; 
    
    

      
    return dp[i][j] = fin ; 
}
int main () {

    cin>>n ; 

    arr.resize(n) ;
    dp.resize( n , vector<long long>( n , 1e14 )) ;  
    for(long long i = 0 ; i<n ; i++) cin>>arr[i] ; 

    long long res = fn ( 0 , n-1 ) ; 

    cout<<res ; 
    return 0 ; 
}