class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0)
            return NULL;
        
        int arr[n];
        arr[0] = 0;
        
        // storing relative differences
        for(int i = 1;i<n;i++)
        {
            arr[i] = prices[i]-prices[i-1];
        }
        int ans=0;
        
        //kadane's algorithm
        for(int i=1;i<n;i++)
        {
            arr[i]+=arr[i-1];
            if(arr[i]<0)arr[i]=0;
            ans = max(ans,arr[i]);
        }
        
        return ans;
        
    }
};
