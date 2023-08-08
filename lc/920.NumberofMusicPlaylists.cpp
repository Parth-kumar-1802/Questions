class Solution {
public:
int mod = 1e9+7;
    long long solve(int length, int songs, int k, int n, vector<vector<long long>> &dp){
        if(length==0 && songs==0){
            return 1LL;
        }
        if(length==0 || songs==0){
            return 0LL;
        }
        if(dp[length][songs]!=-1){
            return dp[length][songs];
        }
        long long ans = (solve(length-1,songs-1,k,n,dp) * (n - (songs-1)))%mod;
        if(songs>k){
            ans=(ans + solve(length-1,songs,k,n,dp) * (songs-k))%mod;
        }

        return dp[length][songs] = ans%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal+1, vector<long long>(n+1,-1));
        return solve(goal,n,k,n,dp);
    }
};