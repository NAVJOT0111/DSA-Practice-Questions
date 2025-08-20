#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    // dfs travere
    void dfs(int node, vector <int>, adjLs[], int vis[]){
        // mark the more as visited
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }

    public:
    int numProvinces(vector <vector<int>> adj, int V){
        vector <int> adjLs[V];

        // to change adjacecy mat to list
        for(int i =0; i<V; i++){
            for(int j = 0; j<V; j++){
                // self nodes not considered
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int cnt = 0;
        for(int i = 0; i<V; i++){
            // if node not visited
            if(!vis[i]){
                cnt++;
                dfs(i, adjLs, vis);
            }
         }

         return cnt;
    }
};

// Time Complexity: O(N) + O(V+2E)
// Space Complexity: O(N) + O(N)