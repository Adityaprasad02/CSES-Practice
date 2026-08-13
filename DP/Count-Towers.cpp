#include<bits/stdc++.h>
using namespace std ; 
using ll = long long ; 


const ll mod = 1e9 + 7 ; 

ll solve ( ll ht , ll currStatus , int n  ){
    if(ht==n) return 1 ; 

    int a = solve( ht + 1 , 0 , n  ) ; 
    int b = solve( ht + 1 , 1 , n ) ; 
    
    ll ans = 0 ; 

    if(currStatus==0){
        ans  = ((2*a)  + b)%mod ; 
    }else{
     ans = (a + (4*b) )%mod; 
    }

    return ans ; 
}


int main () {

    int testCases ; 
    cin>>testCases ;  
    
//    for(int i = 1 ; i<=testCases ; i++) {
//    int mxHt ; cin>>mxHt ;  
//    ll res1  =  solve (  1 ,  0 , mxHt)  ; ll res2 =  solve ( 1 , 1 , mxHt ) ; 
//    cout<<(res1 + res2)%mod<<endl; ; 
//    }
   
vector<vector<ll>> dp ( 1e6+1 , vector<ll>(2 , 0 ) ) ; 
   for(int i = 1 ; i<=testCases ; i++) {
   ll mxHt ; cin>>mxHt ;


   dp[mxHt][0] = 1 ; dp[mxHt][1] = 1 ; 

   for( int ht = mxHt-1 ; ht>=1 ; ht-- ){
            ll a = dp[ht + 1][0] ; 
            ll b = dp[ht + 1][1]  ; 

               dp[ht][0]  = ((2LL*a)  + b)%mod ; 
               dp[ht][1] = (a + (4LL*b) )%mod;
   }

   cout<<(dp[1][1]+dp[1][0])%mod<<endl;
}
   
     return 0 ; 
}