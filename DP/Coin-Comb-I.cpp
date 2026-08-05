#include<bits/stdc++.h>
using namespace std ; 



vector<int> coins ;

vector<int>dp2 ; 

const int mod = 1e9  +  7 ; 

int solve ( int target ){
    if(target==0) return 1 ; 

    if(dp2[target]!=-2) return dp2[target] ; 

    int cnt = 0 ;  

    for(int i = 0 ; i<coins.size() ; i++){


         if(coins[i]<=target){
            int res =  solve ( target - coins[i]) ; 

            if(res>-1){
                cnt =  ( cnt + res ) % mod  ; 
            }
         }
    }

    int ans = (cnt==0) ? -1 : cnt ;  

    return  dp2[target] = ans  ; 
}

int main () {
   int n , target ; 
   cin>>n>>target ; 

   dp2.assign( target+1 , -2 ) ;  

    for(int i = 0 ; i<n ; i++ ){
     int vl ; 
     cin>>vl ; 
    coins.push_back(vl) ; 
   }

   solve(target) ; 

   cout<< ( dp2[target]==-1 ? 0 : dp2[target] )   ; 

    return 0 ; 
}
