#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
            vis[node] = 1;
            ls.push_back(node);

            // traverse all its neighbours
           for(auto it : adj[node]){

            // if the neighbour is not visited
             if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
           }
        }

    public:
    // fuction to return a list containing the dfs traversal of graph
    vector <int> dfsOfGraph(int V, vector <int> adj[]){
        int vis[V] = {0};
        int start = 0;

        // create a list to store dfs
        vector <int> ls;
        // call dfs for starting node
        dfs(start, adj, vis, ls);
        return ls;
    }
};

void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans){
    for(int i = 0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main(){
    vector <int> adj[5];    // not a standard in c++ , In C++, array size must be compile-time constant. int vis[V]; works in GCC as an extension, but not in standard C++.
    //  vector<int> vis(V, 0);

    addEdge(adj, 0 ,2);
    addEdge(adj, 2 ,4);
    addEdge(adj, 0 ,1);
    addEdge(adj, 0 ,3);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}