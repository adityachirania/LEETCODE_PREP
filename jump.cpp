class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(nums.size(),0);
        if(nums.size()==1)return true;
        
        
        int max_sofar = 0;
        bool ans = true;
        
        for(int i = 0;i<nums.size();i++)
        {
            dp[i] = nums[i] + i;
            max_sofar = max(max_sofar,dp[i]);
            
            // if jump capacity is zero 
            if(nums[i]==0) {
                if(dp[i] >= max_sofar && i<nums.size()-1)
                {
                    ans = false;
                    break;
                }
                else if(dp[i]>max_sofar)
                {
                    ans = false;
                    break;
                }
            }
            
            
        }
        
        // return the answer
        return ans;
        
    }
};
