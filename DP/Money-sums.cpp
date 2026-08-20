#include<bits/stdc++.h>
using namespace std ;


vector<vector<int>> dp ; 

int n ;

vector<int> arr ;

// # MEMOIZTION LOGIC DID SELF


bool solve ( int idx  , int target  ){


   if( target==0) return true ;  

   if(idx==n) return false ; 

   if(dp[idx][target]!=-1) return dp[idx][target] ; 
     
    
   bool take = false ; 
   //take ; 
    if(arr[idx] <= target ){
          take = solve (  idx + 1  ,  target - arr[idx] ) ; 
    }

    // not take 
    bool dont = solve ( idx + 1 ,  target ) ; 

    return  dp[idx][target]  = take || dont ; 

}

int main () { 

 

     cin>>n ; 

     arr.resize(n) ; 

 
     
     for(int i = 0 ; i<n  ; i++){
          cin>>arr[i] ; 
     }

    //----------------MY METHOD SELF ACC 1ST TIME USING HASHMAP-------------------------------// 

   //   unordered_map<int,int> mp ; 

   //   for(int i = n-1 ; i>=0 ; i--){
   //      int  no = arr[i] ; 
        
   //      unordered_map<int,int> mp2 ;  
   //         for(auto& it  : mp ){
   //          int num = it.first , freq = it.second ; 

   //            int val = num + no ; 
   //            mp2[val] += freq ; 
   //         }

   //         mp2[no] += 1 ;
           
   //         for(auto & it : mp2){
   //           mp[it.first] += it.second ; 
   //         }

   //   }

   //   vector<int>v ;  ;
   //   for(auto it : mp ){
   //     v.push_back(it.first) ; 
   //   }

   //   sort(v.begin() , v.end()) ; 
     
   //   cout<<v.size()<<endl;
   //   for(auto it : v) cout<<it<<" "; 
   
   //-------------------------------------------------------------------------------------------------

   
   int mxcoins = n ; 
   int mxSum = accumulate(arr.begin() , arr.end() , 0 ) ; 

   dp.assign( mxcoins+1 , vector<int>( mxSum + 1 , -1)) ; 
  
   int ans = 0 ; 

   
   vector<int> res  ; 
    
      for(int target = 1 ; target<=mxSum ; target++){
         if(solve(0 , target )){
            res.push_back(target) ; 
         }
      }



   cout<<res.size()<<endl ;

   for(auto it : res) cout<<it<<" ";

   
   

     return  0 ; 
}