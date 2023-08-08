class Solution {
public:
    bool solve(int ind, vector<int>& nums, int n, int a, int b, vector<vector<int>> &dp){
        if(ind==n){
            if(a==b){
                return 1;
            }
            return 0;
        }
        if(dp[ind][a]!=-1){
            return dp[ind][a];
        }

        bool left = solve(ind+1,nums,n,a+nums[ind],b,dp);
        bool right = solve(ind+1,nums,n,a,b+nums[ind],dp);

        return dp[ind][a] = left||right;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (20000,-1));
        return solve(0,nums,n,0,0,dp);
    }
};