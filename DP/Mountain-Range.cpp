#include<bits/stdc++.h>
using namespace std ; 
using ll = long long ; 


                                        // ##### SELF - DIMAG  ## //
ll n ; 
vector<ll> arr ; 
vector<ll> lmi  , rmi;

vector<ll> dp ; 

// TC = O(n)

ll solve ( ll i ){

    if(i<0 || i>n-1 ) return 0 ; 

    if(dp[i]!=-1) return dp[i] ; 
  ll rt = rmi[i] ; 
        ll lft = lmi[i] ; 
        
           ll mx = max( 1 + solve(rt) , 1 + solve(lft)) ; 
          

           return dp[i] = mx ; 
        
}

int main () {

    cin>>n ; dp.resize ( n , -1 ) ; 

    arr.resize ( n ) , lmi.resize(n) , rmi.resize(n) ; 
    for(ll i = 0 ; i<n ; i++) cin>>arr[i] ; 
    
    stack<ll> st ; 
    for(ll i = n-1 ; i>=0  ; i--){
         
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop() ; 
        }

        if(st.empty()) rmi[i] = n ; 
        else rmi[i] = st.top()  ; 

        st.push(i) ;  
    }

    while(!st.empty()) st.pop() ; 

    for(ll i = 0  ; i<n   ; i++){
          
        while(!st.empty() && arr[st.top()] <= arr[i]){
               st.pop() ; 
        }
        if(st.empty()) lmi[i] = -1 ; 
        else lmi[i] = st.top()  ; 

        st.push(i) ; 
            
    }
    ll res = 1 ; 
     
    for(ll i  = 0 ; i<n ; i++){

        if(i>0 && arr[i]==arr[i-1]) continue ; 
        ll rt = rmi[i] ; 
        ll lft = lmi[i] ; 
        
        if(dp[i]==-1){
           ll ans = max( 1 + solve(rt) , 1 + solve(lft)) ; 
           res  = max(res , ans ) ; 
        }
    }
    cout<<res ; 


    

     return  0 ; 
}