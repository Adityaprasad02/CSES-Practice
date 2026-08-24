#include<bits/stdc++.h>
using namespace std ; 
 
using ll = long long ; 
 
int main () {
    ll n ; 
    cin>>n ; 


      vector< pair< pair<ll,ll> , ll > > p ; 


    vector<ll> endList ; 
                                   
    for(ll i = 1 ; i<=n ; i++){
        ll st , ed , rew ; 
 
        cin>>st>>ed>>rew ; 
 
       p.push_back({{ed , st} , rew }) ; 
  
       endList.push_back(ed) ;  
    }


    sort( p.begin() , p.end() ) ; 
    sort( endList.begin() , endList.end() ) ; 
 
    vector<ll> dp ( n , 0 ) ; 


    for( ll i = 0 ; i<n ; i++){

          ll crrStart = p[i].first.second  ;

          auto it = lower_bound(endList.begin() , endList.end() , crrStart) ;
          
          // this (above ^) will give pointer to that idx where first-End-Val >= crrStart
          // but i need the end-val < crrStart so i can join the forces with them for max
          // simple just an idx back from the pointer idx and we are good  to go 

          ll idx = it - endList.begin() ; 

          ll toAdd =  (idx-1)<0 ? 0 : dp[idx-1] ; 

          ll sum = toAdd + p[i].second ; 

          dp[i] = sum ; 

          if(i-1 > -1 ) dp[i] = max(dp[i-1] , dp[i]) ; 



          
        }
        
        cout<<dp[n-1]<<" ";
 
 
    return 0 ; 
 
 
 
 
}