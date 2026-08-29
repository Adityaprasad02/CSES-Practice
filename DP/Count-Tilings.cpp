#include<bits/stdc++.h>
using namespace std ; 


int ht , wd ;  

const int mod = 1e9 + 7 ; 

int dp[1001][1<<10] ; 

void  fillAndGenerate( int  curr_mask , int new_mask , vector<int>& allPossibleFutureMask , int bit ) {
     



    // will continue from that bit only 

    


    // all filled 
    if(bit==ht){
         allPossibleFutureMask.push_back(new_mask) ; 

         return  ; 
    }


    // for 2 * 1 tilling  -> adjacent tiles of same col

    if ( bit!=ht-1 &&  ((curr_mask & (1<<bit) )== 0 ) && ( (curr_mask & (1<<(bit+1))) == 0 ) ){

          fillAndGenerate ( (curr_mask ^ (1<<bit)) |  (curr_mask ^ (1<<(bit+1))) , new_mask , 
                                                                    allPossibleFutureMask ,  bit + 2  ) ; 
    }



    // for 1 * 2 tiling  -> curr + next col of same level available 

    if(  ((curr_mask & (1<<bit)) == 0 ) && ((new_mask & (1<<bit) )== 0 )    ) {
         
        
        fillAndGenerate ( (curr_mask ^ (1<<bit) ) , (new_mask ^ (1<<bit) ), 
                                                                    allPossibleFutureMask ,  bit + 1  ) ; 
    }
    
 
    // already filled 
    if( ((curr_mask & (1<<bit)) > 0  )){
         fillAndGenerate ( curr_mask , new_mask , allPossibleFutureMask , bit + 1 ) ; 
    }

         
}  

int fn ( int col , int curr_mask ){


    if( col==wd ){
          
          if(curr_mask==0) return 1 ; // all col filled 
          else return 0 ; // exceeded the boundary 
    }

    if(dp[col][curr_mask]!=-1) return dp[col][curr_mask] ; 
     
          
    vector<int> allPossibleFutureMask ; // all new_masks which will formed after completely filling curr col 
                                        // will be pushed in this 

    int new_mask = 0 ; 

    fillAndGenerate( curr_mask , new_mask , allPossibleFutureMask , 0  ) ;  

    int ways = 0 ; 

    for( int allMask : allPossibleFutureMask ){
          
        ways  = (ways + fn( col + 1 , allMask )) % mod  ; 
    }


    return dp[col][curr_mask] =  ways ; 
    
     
}


int main(){
    

    cin>>ht>>wd ; 

    memset( dp , -1 , sizeof(dp)) ; 

    int res = fn ( 0 , 0 ) ; 



    cout<<res<<endl ; 

     
     return 0 ; 
}
