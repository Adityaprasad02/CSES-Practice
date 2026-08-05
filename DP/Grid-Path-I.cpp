#include<bits/stdc++.h> 
using namespace std ; 

using ll = long long ; 

ll n ; 
vector<vector<char>> grid ; 


ll solve ( ll i , ll j ) {


    if(i==n-1 && j==n-1) return 1  ; 

    ll dir[2][2] = { {0 , 1} , {1 , 0} } ; 
    
    ll take = 0 ; 

    for( ll idx = 0 ; idx<2 ; idx++){
        ll nr = dir[idx][0] + i  , nc = dir[idx][1] + j ;
        
        if( nr>=0 && nc>=0 && nr<n && nc<n ){

            if(grid[nr][nc]!='*'){
             take  = take +  solve(nr,nc)   ;
            }
        }

    }


    return take ; 
}


int main () {
    cin>>n ; 
    grid.resize( n , vector<char>( n )) ; 

    for(ll i = 0 ; i<n ; i++){
        for(ll j = 0 ; j<n ; j++){
            cin>>grid[i][j] ; 
        }
    }

    // only right , down -> no of ways to reach the n-1 , n-1 cell 

    if(grid[0][0]=='*' || grid[n-1][n-1]=='*'){
        cout<<0; 
        return 0 ;
    }

    

//    ll res  = solve ( 0 , 0 ) ;  // top-down

//     cout<<res ; 


const ll mod = 1e9 + 7 ; 

vector<vector<ll>> dp ( n , vector<ll> ( n , 0  )) ; 


// base case 
dp[n-1][n-1] = 1 ; 


// write loop in rev dirn && copy the recurrence 


for( ll i = n-1 ; i>=0 ; i--){
    for(ll j = n-1; j>=0 ; j--){

       if(i==n-1 && j==n-1) continue ;
        
        if(grid[i][j]=='*') {
              dp[i][j] = 0 ; 
              continue ; 
        } 

    ll dir[2][2] = { {0 , 1} , {1 , 0} } ; 
    
    ll take = 0 ; 

    for( ll idx = 0 ; idx<2 ; idx++){
        ll nr = dir[idx][0] + i  , nc = dir[idx][1] + j ;
        
        if( nr>=0 && nc>=0 && nr<n && nc<n ){

            if(grid[nr][nc]!='*'){
             take  = ( take +  dp[nr][nc] ) % mod   ;
            }
        }

    }
     dp[i][j] = take ; 
    }
}

cout<<dp[0][0] ; 

    return 0 ; 

}