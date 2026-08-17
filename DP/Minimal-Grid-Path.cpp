#include <bits/stdc++.h>
using namespace std;


// #self dry run and coded

int n;

vector<vector<char>> mat;
vector<vector<bool>> vis;

int main() {

    cin >> n;

    mat.resize(n, vector<char>(n));
    vis.resize(n, vector<bool>( n , false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<pair<int,int>> mins ; 

    mins.push_back({0,0}) ; 
    vis[0][0] = 1 ; 
    string ans ; 
    ans.push_back(mat[0][0]) ; 

    while (mins.size() > 0 )
    { 
            
         vector<pair<int,int>> nxt ; 
         char minChar = '~' ; 

         for(auto it  : mins ){
               int r = it.first , c = it.second ; 

               if(r+1<n && !vis[r+1][c] ){
                   nxt.push_back({r+1,c}) ; 
                   vis[r+1][c] = true ; 
                   minChar = min ( minChar , mat[r+1][c] ) ; 
               }

                  if(c+1<n && !vis[r][c+1] ){
                   nxt.push_back({r,c+1}) ; 
                   vis[r][c+1] = true ; 
                   minChar = min ( minChar , mat[r][c+1] ) ; 
               }
         }

         if(minChar!='~') ans.push_back(minChar) ; 

         mins.clear() ; 

         for(auto it : nxt){
            int i = it.first , j = it.second ; 
            if(mat[i][j]==minChar){
                mins.push_back({i , j}) ; 
            }
         }
    }

    cout<<ans ; 
    

 
    return 0;
}