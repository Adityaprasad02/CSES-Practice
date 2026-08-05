#include<bits/stdc++.h>
using namespace std ; 


vector<int>dp ; 
const int mod = 1e9 + 7 ; 

int diceComb( int n ) {

    if(dp[n]!=-1) return dp[n] ; 
    
    if(n==0) return dp[n] = 1 ; 

    int sum = 0 ;
    
    for(int i =  1 ; i<=min(n,6) ; i++){
        sum = ( sum + diceComb(n-i) ) % mod ; 
    }

    return dp[n] = sum ; 
}


int main () {
   

    int n ; cin>>n ; 
    dp.assign( n+1 , -1 ) ; 

    diceComb(n) ; 

    cout<<dp[n] ; 
    return 0 ; 
}
