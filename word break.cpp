class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (int i=1;i<=n;++i){
            for (string j: wordDict){
                int l = j.length();
                
                if (i-l >= 0 && dp[i-l] == 1){
                    if (j.compare(s.substr(i-l,l)) == 0) {
                        dp[i] = 1;
                        break;
                    } 
                }
            }
        }
        return dp[n];
    }
};
