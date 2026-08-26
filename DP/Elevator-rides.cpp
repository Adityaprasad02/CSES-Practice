#include<bits/stdc++.h>
using namespace std ; 
using ll = long long ;


// ek wt ko kisi grp me add -> # (add a bit ) -> mask | (1<<i)
 
int n , mxWt  ; 
 
vector<int> wt ; 
 
vector<pair<int,int>> dp ; 
 
pair<int,int> fn ( int mask ){

    if(mask==0) return {1 , 0 } ; 


    if(dp[mask].first!=1e9) return dp[mask] ; 

   
     pair<int,int> cand = {1e9 , 1e9 } ; 
    
    for(int i = 0 ; i<n ; i++){
         
        bool isSet = mask & (1<<(n-i-1)) ; 

        
        if(isSet){
            int newMask = mask ^ (1<<(n-i-1)) ; // togle the bit to indicate we have taken it ;

            auto it  =  fn ( newMask ) ;
            
            int curr_grps = it.first , crr_wt = it.second ; // ulta karke laa rha add 
            
            if(wt[i] + crr_wt <= mxWt) {
                cand = min ( cand , { curr_grps , crr_wt + wt[i]} ); 
            }else{
                cand = min ( cand , { curr_grps + 1 , wt[i] } ) ; 
            }
        }

        

    }

    return dp[mask] = cand ; 
}
 
 
int main (){
 
    cin>>n>>mxWt ;
    
    wt.resize( n , 0 ) ; 
 
    dp.resize ( 1<<n , {1e9 , 1e9 }) ; 
 
    for(int i = 0 ; i<n ; i++) cin>>wt[i] ; 
    
 
    int mask = (1<<(n)) - 1  ; 

   cout<<fn(  mask  ).first ; 

   //cout<<" { "<<dp[0].first<<" , "<<dp[0].second<<" } " ; 
 
    return 0 ; 
}