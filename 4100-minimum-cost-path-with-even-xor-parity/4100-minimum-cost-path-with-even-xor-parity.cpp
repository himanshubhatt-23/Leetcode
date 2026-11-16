class Solution {
public:
    int minActivationCost(vector<vector<int>>& edges, vector<int>& val) {
        
        int ans = INT_MAX;
        int n = val.size();
        for(auto& u:edges){
            int x = __builtin_popcount(val[u[0]]) % 2;
            int y = __builtin_popcount(val[u[1]]) % 2;

            if(x == y) ans = min(ans, u[2]);

        }
        vector<vector<int>> adj(n);
        for(auto& u:edges){
            int x = __builtin_popcount(val[u[0]]) % 2;
            int y = __builtin_popcount(val[u[1]]) % 2;

            if(x == 0 && y == 1) adj[u[0]].push_back(u[2]);
            else if(x == 1 && y == 0) adj[u[1]].push_back(u[2]);            
        }

        for(int r=0; r<n; r++){
            if(adj[r].size() >= 2){
                sort(adj[r].begin(), adj[r].end());
                ans = min(ans, adj[r][0]+adj[r][1]);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};