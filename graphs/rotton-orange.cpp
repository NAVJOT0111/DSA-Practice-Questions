#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangeRotting(vector <vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        // {{row, col}, time}
        queue <pair<pair<int, int>, int>> q;
        // vector <vector<int>> vis;
        int vis[n][m];
        int cntFresh = 0;

        for(int i =0; i<n; i+++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0}); 
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = { 0, +1, 0, -1};
        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first ;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for(int i =0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && ncol >=0 && ncol <m 
                    && vis[nrow][ncol] != 2 
                    && grid[nrow][ncol] == 1){
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = 2;
                        cnt++;
                    }
            }
        }
        // for(int i = 0; i<n; i++){
            // for(int j = 0; j<m; j++){
                // if(vis[i][j] != 2 && grid[i][j] == 1){
                //     return -1;
                // }
            // }
        // }

        if(cnt != cntFresh) return -1;

        return tm;
    }

};