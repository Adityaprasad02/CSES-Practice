
#include <bits/stdc++.h>
using namespace std  ;
using ll = long long ; 

vector<vector<ll>> t  ;
vector<ll>underCount  , ans  ;
   ll n ;  

ll sumHt = 0 ; 

ll cntNodes( ll nd , ll par , ll ht ) {

    ll cnt = 1 ; sumHt += ht ; 
    for(auto it : t[nd]){
        if(it!=par){
            cnt += cntNodes( it , nd , 1 + ht ) ; 
        }
    }


    return underCount[nd] = cnt ; 
}


void treeDis ( ll nd  , ll  par , ll prevHt  ){

        ans[nd] = prevHt + n - ( 2 * ( underCount[nd] ) ) ;  

        for(auto it : t[nd] ){
            if(it!=par){
                treeDis( it , nd , ans[nd] ) ; 
            }
        } 
}

int main()
{

   cin>>n ;

   t.resize(n) ; 
   underCount.resize(n)   ;
   ans.resize(n) ;  
   
   for(ll i  = 0 ; i<n-1 ; i++){
       ll u , v ; 
       
       cin>>u>>v ; 
       
       t[u-1].push_back(v-1) ; 
       t[v-1].push_back(u-1) ; 
   }

   cntNodes( 0 , -1 , 0  ) ; 

   ans[0] = sumHt ; 

        for(auto it : t[0] ){
            if(it!=-1){
                treeDis( it , 0 , ans[0] ) ; 
            }
        } 



   for(auto it : ans ){
     cout<<it<<" "; 
   }



    return 0;
}