class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n==0)
            return NULL;
        
        int last_highest = 0;
        
        // traverse from left to right 
        int value[n];
        for(int i = 0;i<n;i++)
        {
            last_highest = max(last_highest,height[i]);
            value[i] = last_highest - height[i];
        }
        
        //traversing right to left
        last_highest = 0;
        int ans = 0;
        for(int i= n-1;i >= 0;i--)
        {
            last_highest = max(last_highest,height[i]);
            value[i] = min(value[i],last_highest - height[i]);
            ans += (value[i]);
        }
        
        return ans;
        
    }
};
