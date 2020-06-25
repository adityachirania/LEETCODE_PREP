class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> ans1(n,0),ans2(n,0);
        
        for(int i = 1;i < n;i++)
        {
            if(rating[i] > rating[i-1])
                ans1[i] = ans1[i-1] + 1;

        }
        int sum = 0;
        for(int i = n-2;i>=0;i--)
        {
            if(rating[i] > rating[i+1])
                ans2[i] = ans2[i+1] + 1;
            
            ans1[i] = max(ans1[i],ans2[i]);
            sum+=ans1[i];
        }
        ans1[n-1] = max(ans1[n-1],ans2[n-1]);
        sum+=ans1[n-1];
        return sum + n;
    }
};
