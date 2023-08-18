class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,vector<int>> adj;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> order(n);

        for(int i=0;i<n;i++){
            order[i] = adj[i].size();
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=order[i]+order[j];
                for(auto x:adj[i]){
                    if(x==j){
                        temp--;
                    }
                }
                ans=max(temp,ans);
            }
        }

        return ans;
    }
};