#include<bits/stdc++.h>
using namespace std  ; 


 // BINARY UPLIFTING OF TREE / GRAPH

vector<vector<int>> tree , anc  ; 
vector<int> height ; 
    int n , q , maxBits  ; 

void firstParentDfs( int node , int par  , int ht) {
   

      anc[node][0] = par ; 

      height[node] = ht ; 

      for(auto child : tree[node]){
         if( child != par ){
            firstParentDfs ( child , node , 1 + ht ) ; 
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

int LCAUsingBinaryLifting( int  u ,  int v )  {
     
      // very easy 

      // by default closest to root should be  u and farhest should be v ;  
      // if ain't then swap both 
      if(height[v] < height[u]){
         swap( u , v ) ; 
      }
   
      // find anc of v as on the same level as u 
      // start from (2^bit ) farthest so that can be reached fast 
      for( int i = maxBits-1 ; i>=0 ; i--){
         
         int ht = (1<<i) ; 

         int aboveNodesHt = height[v] - ht ; 
         
         if( aboveNodesHt >= height[u] ){
             
              v = anc[v][i] ; // changed the node ; 
         }

      }

      // now u and v at same level 
      
      // check if u==v then return u ; 
      if(u==v) return u ; 


      // find the kh par of both u and v which is same 
      // start from lowest jump

      for(int i = maxBits-1 ; i>=0 ; i--){
            
            if(anc[u][i] != anc[v][i]){
                // if not same then make them jump at the same level 
                u = anc[u][i] ; 
                v = anc[v][i] ; 
            }
      }


      // in last there would be scenario like u,v their immediate par
      // i.e 0th parent at ht 1 is ans ; 

      return anc[v][0] ; 




}



int main () { 
    cin>>n>>q ; 

    tree.resize ( n+1 ) ;
    
    maxBits = log2(n) + 1 ;   // log2n is mxht for perfect / compl binary tree ; 
                                // suppose a skewed tree having 100 nodes , so mxht = 99 i.e node-1 ; 
                                // so for max bits i.e 2^bits = totNodes ->->  bits = log2(totNodes) + [1]


    anc.resize( n+1 , vector<int>( maxBits , -1  ) ) ; 

    height.resize(n+1 , 0) ; 

    for(int i = 2 ; i<=n ; i++ ){

       int par ; cin>>par ;
       
       tree[par].push_back(i);
    }

    firstParentDfs ( 1 , 1 , 0 ) ;  // intitial fill  first parent  dfs 

    preprocessKthParent() ; // fill all parents 

    for( int i = 1 ; i<=q ; i++ ){

         int u , v ; 

          cin>>u>>v ; 

          if(u==v){
            cout<<u<<endl ; 
          }else{

          cout<<LCAUsingBinaryLifting( u , v )<<endl ; 
          }

    }

    return 0 ; 
}