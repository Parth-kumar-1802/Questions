class Solution {
public:
    bool solve(int i, string s1, int j, string s2, int k, string s3, vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size()){
            if(i+j==k){
                return true;
            }
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        bool first = false;
        if(i!=s1.size() && s1[i]==s3[k]){
            first = solve(i+1,s1,j,s2,k+1,s3,dp);
        }

        bool second = false;
        if(j!=s2.size() && s2[j]==s3[k]){
            second = solve(i,s1,j+1,s2,k+1,s3,dp);
        }

        return dp[i][j] = first || second;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1,-1));
        return solve(0,s1,0,s2,0,s3,dp);
    }
};