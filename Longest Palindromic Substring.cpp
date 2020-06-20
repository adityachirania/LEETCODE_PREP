class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1)return s;
        int S = s.size();
        int midletter = 1;
        int ans = 1;
        
        // will store the ends of palindromw
        int start = 0;
        int end = 0;
        
        // odd lengths palindromes
        for(midletter = 1;midletter<S-1;midletter++)
        {
            int l = midletter-1,r=midletter+1;
            int temp_ans = 1;
            while(l>=0 && r<s.size())
            {
                if(s[l]==s[r])temp_ans+=2;
                else break;
                l--;
                r++;
            }
            if(temp_ans>ans)
            {
                ans = max(ans,temp_ans);
                start = l+1;
                end = r-1;
            }
            
        }
        
    
        //checking for even length ones
        for(midletter=0;midletter<S-1;midletter++)
        {
            int l = midletter,r=midletter+1;
            int temp_ans=0;
             while(l>=0 && r<s.size())
            {
                if(s[l]==s[r])temp_ans+=2;
                else break;
                l--;
                r++;
            }
             if(temp_ans>ans)
            {
                ans = max(ans,temp_ans);
                start = l+1;
                end = r-1;
            }
        }
        
        return s.substr(start,ans);
        
        
        
    }
};
