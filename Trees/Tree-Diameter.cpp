

#include <bits/stdc++.h>
using namespace std  ;

std::vector<vector<int>> t  ;

int dia = 0 ; 


int solve(int nd , int par ){

    
    int prevMax =  0 , ht = 0  ; 
    
     for(auto it : t[nd]){
         if(it!=par){
             int currHeight = 1 + solve(it , nd ) ; 

             dia = max( dia , prevMax + currHeight ) ; 
             
             prevMax = max(prevMax , currHeight ) ; 

             ht = max( ht , currHeight) ; 
         }
     }

     
     return  ht  ; 
}

int main()
{
   int n ; 
   cin>>n ;
   
   if(n<2) {
    cout<<0 ; 
   }
   else{
   t.resize(n) ; 
   
   for(int i  = 0 ; i<n-1 ; i++){
       int u , v ; 
       
       cin>>u>>v ; 
       
       t[u-1].push_back(v-1) ; 
       t[v-1].push_back(u-1) ; 
   }
   
   
   solve ( 0 , -1  ) ; 
   
   cout<<dia ; 
}

    return 0;
}