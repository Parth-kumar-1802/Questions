class Solution {
public:
    int solve(int ind, string s, int n, set<string> mp, vector<int> &dp){
        if(ind==n){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int ans=0;
        //interim sub string
        string sub="";
        for(int i=ind;i<n;i++){
            sub+=s[i];
            if(mp.find(sub)!=mp.end()){
                ans=max(solve(i+1,s,n,mp,dp),ans);
            }
        }
        return dp[ind] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> mp;
        for(int i=0;i<wordDict.size();i++){
            mp.insert(wordDict[i]);
        }

        vector<int> dp(s.size(),-1);

        return solve(0,s,s.size(),mp,dp);
    }
};