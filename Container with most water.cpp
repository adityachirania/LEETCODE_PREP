class Solution {
public:
    int maxArea(vector<int>& height) {
       
        int ptr1 = 0;int ptr2 = height.size()-1;
        int ans = 0;
        while(ptr1 < ptr2)
        {
            cout<<ptr1<<" "<<ptr2<<"\n";
            ans = max(ans,min(height[ptr1],height[ptr2])*(ptr2-ptr1));
            if(height[ptr1]<height[ptr2])ptr1++;
            else if(height[ptr2]<height[ptr1])ptr2--;
            else {ptr1++;ptr2--;}
        }
        return ans;
    }
};
