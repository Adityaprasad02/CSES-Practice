#include<bits/stdc++.h> 
using namespace std ; 

using ll  = long long ; 

ll n  ; 
vector<ll> dp ;  

ll solve ( ll no ){

     if(no>=0 && no<10 ) return 1 ; 

     if(dp[no]!=-1) return  dp[no] ; 
     
     string str = to_string(no) ; 

     ll hash[10] = {0}  ;

     ll sum = 1e9  ; 
     
     for(ll i = 0 ; i<str.size() ; i++){
          
        ll num = str[i] - '0' ; 

        if(num==0) continue ; 

        if(hash[num]==0){
           sum = min ( sum  , 1 + solve( no - num ) ) ; 
        }
     }


     return dp[no]  = sum ; 
     

}

int main () { 
   
     cin>>n ; 

     dp.resize( n+1 , -1 ) ; 
     
     ll res = solve ( n ) ; 
  
     cout<<res ; 
}
