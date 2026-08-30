#include<bits/stdc++.h>
using namespace std ;


int n , q ; 
vector<int> salary , seg ; 
vector<array<int, 3>> orders;

int removeUpdate ( int rankCurrSal ,  int st , int end , int par  ){ 
    
      if(end<rankCurrSal || st>rankCurrSal) return seg[par]  ; // because for a par node we want both child 
      
      if(st==end){
        // update -> #decrease
        seg[par] -= 1 ;
        return seg[par] ; 
      }

     int mid = ( st + (end-st)/2 ) ; 

        if(rankCurrSal <=mid ) removeUpdate (  rankCurrSal , st , mid , 2*par + 1) ; 
       else removeUpdate ( rankCurrSal  , mid+1 , end , 2*par + 2 ) ; 
    
      return  seg[par] =  seg[2*par+1] + seg[2*par+2] ; 

}

int increaseUpdate( int rankNewSal ,  int st , int end , int par ){
       if(end<rankNewSal || st>rankNewSal) return seg[par]  ; // because for a par node we want both child 
      
      if(st==end){
        // update -> #increase
        seg[par] += 1 ;
        return seg[par] ; 
      }

     int mid = ( st + (end-st)/2 ) ; 

       if(rankNewSal <=mid ) increaseUpdate (  rankNewSal , st , mid , 2*par + 1) ; 
       else  increaseUpdate ( rankNewSal  , mid+1 , end , 2*par + 2 ) ; 
    
      return  seg[par] =  seg[2*par+1] + seg[2*par+2] ; 
}


int query ( int lft , int rt , int st , int end , int par ){
       
    if(end<lft || st > rt) return 0 ; // out of range ; 

    if( lft <= st && end<=rt ) return seg[par] ; // already have been calculated while updating 


      int mid = ( st + (end-st)/2 ) ; 
 

      int resLeft =  query( lft , rt , st , mid , 2*par + 1 ) ; 
      int resRight =  query( lft , rt , mid+1 , end , 2*par + 2 ) ; 

       return resLeft + resRight ; 
       
}


int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q ; 

    salary.resize(n , 0) ; 

    vector<int> st ; // to store unique sorted elements ; 

    for(int i = 0 ; i<n ; i++ ){
          cin>>salary[i] ; 
          st.push_back(salary[i]) ; 
    } 
    
    
    for(int i = 1 ; i<=q ; i++){
         
        char ch ; int num1 , num2 ;  cin>>ch>>num1>>num2 ; 

        if(ch=='!') { // update
            st.push_back(num2) ; 
            orders.push_back({'U' , num1 , num2}) ; 
        }

        if(ch=='?'){

          // for ? a b the a,b can be from 1 to 1e9 so we dont know if they will be existing in crr array
          st.push_back(num1) ;
          st.push_back(num2) ; 
          orders.push_back({'Q',num1,num2}) ; 
        } 
    }
    
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());       
    
    
    seg.resize ( 4*st.size() + 1 , 0) ; 

     for(int i = 0 ; i<n ; i++){
         int num = salary[i] ; 
         
         auto it = lower_bound(st.begin(), st.end(), num) ; // points to first locn in set where num appears
         
         int idx = it - st.begin() ; // idx is rank of them in sorted order 

         increaseUpdate( idx , 0 , st.size() - 1 , 0  ) ; // update the current element's rank freq in seg tree ; 

     }

    for(auto it : orders){
         if(it[0]=='Q'){
             
             int lowSal = it[1] , highSal = it[2] ; 

             // get Rank of lowSal from set 
             auto it1 = lower_bound(st.begin(), st.end(), lowSal) ; int rankLow = it1 - st.begin() ; 

             // get Rank of highSal from set ; 
             auto it2 = lower_bound(st.begin(), st.end(), highSal) ; int rankHigh = it2 - st.begin(); 

             int res = query( rankLow , rankHigh , 0 , st.size()-1 , 0 );   //  [a.....b] to get a...b sub 

             cout<<res<<'\n' ; 


         }else if ( it[0]=='U'){
              
            int employeeNo = it[1] , newSal = it[2] ; 

            int currSal = salary[employeeNo-1] ; 

             auto it1 = lower_bound(st.begin(), st.end(), currSal); int rankCurrSal = it1 - st.begin(); 

             // get Rank of highSal from set ; 
             auto it2 = lower_bound(st.begin(), st.end(), newSal) ; int rankNewSal = it2 - st.begin() ; 

            removeUpdate ( rankCurrSal  , 0 , st.size() - 1 , 0  ) ;
            
            increaseUpdate ( rankNewSal , 0 , st.size() - 1 , 0  ) ; 

            // update in array also 

            salary[employeeNo-1] = newSal ; 


         }
    }

  
     return 0 ; 
}