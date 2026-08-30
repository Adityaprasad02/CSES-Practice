#include<bits/stdc++.h>
using namespace std ; 


// Pre-req of this ques => CP_Practice -> seg tree/fenwick -> coord-compression technique



/*

Key Idea -> for an element X the subseq ending at it is sum of each
            elem's subseq ending at them  to the left of X which are < it 

            in last add 1 , cause {itself} 

            so if rank(X) is k 
            i want seg[ rank(0)......rank(k-1)  ]

            */
           
           int n ; 
           vector<int>arr , seg  ; 
           
           const int mod = 1e9 + 7 ; 

int query ( int lft , int rt , int st , int end , int par  ){
       
    if(end<lft || st > rt) return 0 ; // out of range ; 

    if( lft <= st && end<=rt ) return seg[par] ; // already have been calculated while updating 


      int mid = ( st + (end-st)/2 ) ; 
 

      int resLeft =  query( lft , rt , st , mid , 2*par + 1 ) ; 
      int resRight =  query( lft , rt , mid+1 , end , 2*par + 2 ) ; 

       return (resLeft + resRight)%mod   ; 
       
}

int update ( int rank , int st , int end , int par , int val ){ 
      
      if(end<rank || st>rank) return seg[par]  ; // because for a par node we want both child 
      
      if(st==end){
        // update 
        seg[par] = (seg[par] + val )%mod;

        //cout<<seg[par]<<endl;
        return seg[par] ; 
      }

     int mid = ( st + (end-st)/2 ) ; 

       int resultLeft = update ( rank , st , mid , 2*par + 1,val) ; 
       int resultRight = update ( rank , mid+1 , end , 2*par + 2,val ) ; 
    
      return  seg[par] =  (resultLeft + resultRight)%mod  ; 

}


int main () {

    cin>>n ; 

    arr.resize( n ) ; 
 

    for(int i = 0 ; i<n ; i++) {
         cin>>arr[i] ; 
    }

    vector<int> coords = arr;

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    int sz = coords.size() ; 

    seg.resize( 4*sz + 1  , 0 ) ; 

    int ans = 0 ; 


    for(int i = 0 ; i<n ; i++){
           int num = arr[i] ; 
         
         int idx = lower_bound(coords.begin(), coords.end(), num) - coords.begin(); 


        int smallerElementsToLeft =  query ( 0 , idx - 1 , 0 , sz-1 , 0 ) ; 

        //cout<<" for "<<num<<" -> "<<smallerElementsToLeft<<endl;

         ans =  update( idx , 0 , sz - 1 , 0 , smallerElementsToLeft+1) ; 

         

    }
    
    cout<<ans ;





    return 0  ;
}