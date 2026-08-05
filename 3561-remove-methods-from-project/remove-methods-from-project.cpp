class Solution {
public:
    void dfs(int node,vector<vector<int>> &graph,vector<int> &visited){
        visited[node]=1;
        for(int next:graph[node]){
            if(visited[next]==0){
                dfs(next,graph,visited);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(auto &edge:invocations){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
        }
        vector<int>visited(n,0);
        dfs(k,graph,visited);
        for(auto &edge: invocations){
            int u=edge[0];
            int v=edge[1];
            if(visited[u]==0 && visited[v]==1){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }

    
};