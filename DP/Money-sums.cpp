#include<bits/stdc++.h>
using namespace std ; 

int main () { 

     int n ; 

     cin>>n ; 

     vector<int> arr(n) ;
     
     for(int i = 0 ; i<n  ; i++){
          cin>>arr[i] ; 
     }


     unordered_map<int,int> mp ; 

     for(int i = n-1 ; i>=0 ; i--){
        int  no = arr[i] ; 
        
        unordered_map<int,int> mp2 ;  
           for(auto& it  : mp ){
            int num = it.first , freq = it.second ; 

              int val = num + no ; 
              mp2[val] += freq ; 
           }

           mp2[no] += 1 ;
           
           for(auto & it : mp2){
             mp[it.first] += it.second ; 
           }

     }

     vector<int>v ;  ;
     for(auto it : mp ){
       v.push_back(it.first) ; 
     }

     sort(v.begin() , v.end()) ; 
     
     cout<<v.size()<<endl;
     for(auto it : v) cout<<it<<" "; 


     return  0 ; 
}