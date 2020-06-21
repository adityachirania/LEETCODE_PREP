class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        //the maximum element needed to be stored
        int maxele = nums[0];
        for(int i = 0;i<nums.size();i++)
        {
            maxele = max(maxele,nums[i]);
            if(i>0)
            {
                nums[i] += nums[i-1];
            }
            if(nums[i]<0)nums[i]=0;
            ans = max(ans,nums[i]);
            
        }
        // return largest element if all elements are negative 
        if(maxele<0)return maxele;
        return ans;
        
        
        
    }
};
