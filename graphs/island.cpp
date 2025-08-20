#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){

        //Mark starting cell as visited and push it into a queue.

        vis[row][col] = 1;
        queue <pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){      // While queue is not empty:
            int row = q.front().first;
            int col = q.front().second;
            q.pop();        // Pop the front cell.

            // tarverse and mark if visited 
            for(int drow = -1; drow <=1; drow++){       //Look at all 8 possible directions (since you allowed -1, 0, +1 deltas for row and col)
                for(int dcol = -1; dcol <=1; dcol++){
                    int nrow = row + drow;
                    int ncol = col + dcol;
                    if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m    // check for validity
                         && grid[nrow][ncol] == '1'     // check for land       
                        && !vis[nrow][ncol]){       // check for visited
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }       
                }
            }
        }
    }

    public:
    // function to find no of islands
    int island(vector <vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> vis(n, vector<int>(m,0));
        int cnt =0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }

};