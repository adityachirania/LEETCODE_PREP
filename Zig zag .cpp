class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<char> rows[numRows];
        int ptr = 0;
        int val = -1;
        for(int i = 0; i < s.size(); i++ )
        {
            if(ptr==0)
            {
                val = 1;
            }
            else if(ptr == numRows-1)
            {
                val = -1;
            }
            
            rows[ptr].push_back(s[i]);
            ptr += val;
        }
        string s1 = "";
        for(int i = 0;i < numRows;i++)
        {
            for(int j = 0;j<rows[i].size();j++)
            {
                s1 += rows[i][j];
            }
        }
        return s1;
            
    }
};
