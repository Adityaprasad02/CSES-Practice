#include<bits/stdc++.h>
using namespace std  ; 


 // BINARY UPLIFTING OF TREE / GRAPH

vector<vector<int>> tree , anc  ; 
    int n , q , maxBits  ; 

void firstParentDfs( int node , int par ) {
   

      anc[node][0] = par ; 

      for(auto child : tree[node]){
         if( child != par ){
            firstParentDfs ( child , node ) ; 
         }
      }
      
}

void preprocessKthParent() {
     
     // Ex -> maxBits = 7 i.e  [ 0 1 2 3 4 5 6 ] 
     for( int i = 1 ; i<=n ; i++ ){
         for ( int j  = 1 ; j<=maxBits-1  ; j++ ){
              
            if(anc[i][j-1]!=-1){
             anc[i][j] = anc[anc[i][j-1]][j-1] ;
            } 
         }
     } 
}


int findKthParent( int node , int kthPar ) {
    
    for( int j = maxBits - 1 ; j>=0 ; j-- ){
          
          if( (kthPar & (1<<j)) > 0  ){
              if(anc[node][j]==-1) return -1 ; 

              node = anc[node][j] ; 
          }
    }
     
    
  return node   ; 
}

int main () { 
    cin>>n>>q ; 

    tree.resize ( n+1 ) ;
    
    maxBits = log2(n) + 1 ;   // log2n is mxht for perfect / compl binary tree ; 
                                // suppose a skewed tree having 100 nodes , so mxht = 99 i.e node-1 ; 
                                // so for max bits i.e 2^bits = totNodes ->->  bits = log2(totNodes) + [1]


    anc.resize( n+1 , vector<int>( maxBits , -1  ) ) ; 

    for(int i = 2 ; i<=n ; i++ ){

       int par ; cin>>par ;
       
       tree[par].push_back(i);
    }

    firstParentDfs ( 1 , -1 ) ;  // intitial fill  first parent  dfs 

    preprocessKthParent() ; // fill all parents 


    


    for ( int  i = 1 ; i<=q ; i++ ){
        int node , kthPar ; 

        cin>>node>>kthPar ; 

        cout<<findKthParent( node , kthPar )<<endl ; 
    }
    return 0 ; 
}