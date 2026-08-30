#include<bits/stdc++.h>
using namespace std ;
using ll = long long  ; 

ll dp[2][20][2][11] ; 

ll solve(string num , bool tight , ll idx , bool lz , ll prev ){
       
     if(idx == (ll)num.size() ) return 1 ; 

     if(dp[tight][idx][lz][prev]!=-1) return dp[tight][idx][lz][prev] ; 

     ll lb = 0 ; 
     ll ub = (tight) ? (num[idx] - '0') : 9 ; 

     ll ans = 0 ; 

     for(ll dig = lb ; dig<=ub ; dig++ ){

          if(dig==prev && !lz ) continue ; 

          ans += solve( num , (tight && dig==ub) , idx + 1 , (dig==0 && lz ) , dig ) ; 
     }

     return dp[tight][idx][lz][prev] = ans ; 
}

ll fn( ll num1 , ll num2 ){
    string l = to_string(num1-1) ; 
    string r = to_string(num2) ;
    
    memset(dp , -1 , sizeof(dp)) ; // fill the 1d/2d/3d dp with a value 
    ll ans_l = solve( l , 1 , 0 , 1 , 0)  ; 

    memset(dp , -1 , sizeof(dp)) ; 
    ll ans_r = solve( r , 1 , 0 , 1 , 0 ) ; 
    
    return ans_r - ans_l  ; 
    
}

int main() {
    
    ll num1 , num2 ; 
    
    cin>>num1>>num2 ; 

     ll res  = fn(num1 , num2 ) ; 
     
     cout<<res ; 
     
     

     return 0  ; 
}
