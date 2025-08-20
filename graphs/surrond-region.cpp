#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    vector <vector<char>> fill(int n, int m, vector <vector<char>> mat){
        vector <vector<int>> vis(n, vector<int>(m,0));

        // traverse first row and last row
        for(int j = 0; j<m ; j++){

            // first row
            if(!vis[0][j] && mat[0][j] == '0'){
                dfs(0,j, vis, mat);
            }

            // last row
            if(!vis[n-1][j] && mat[n-1][j] == '0'){
                dfs(n-1, j, vis, mat);
            }
        }

        for(int i =0; i<n; i++){
            // first column
            if(!vis[i][0] && mat[i][0] == '0'){
                dfs(i,0,vis,mat);
            }

            if(!vis[i][m-1] && mat[i][m-1] == '0'){
                dfs(i, m-1, vis,  mat);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == '0')
                mat[i][j] = 'X';
            }
        }

        return mat;
    }

};