class Solution {
public:
    bool solve(int start, int end, vector<int>& nums, int m, int tot, vector<vector<int>> &dp){
        if(end==start+1){
            return true;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        //brak the left one
        bool left=false;
        if(tot-nums[start]>=m){
            left=solve(start+1,end,nums,m, tot-nums[start],dp);
        }
        bool right=false;
        if(tot-nums[end]>=m){
            right=solve(start,end-1,nums,m,tot-nums[end],dp);
        }
        
        return dp[start][end] = left||right;
    }
    
    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size();
        if(n==1){
                return true;
        }
        int tot=accumulate(nums.begin(),nums.end(),0LL);
        vector<vector<int>> dp(n+1,vector<int> (n+1, -1));
        
        return solve(0,n-1,nums,m,tot,dp);
    }
};