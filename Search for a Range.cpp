class Solution {
public:
        int leftindex(vector<int> &nums,int &tar){
            int l = 0,r = nums.size()-1;
            int ans = -1;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if(nums[mid] == tar){
                    ans = mid;
                    r = mid-1;
                }
                else if(nums[mid]>tar){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            return ans;
        }
        int rightindex(vector<int> &nums,int &tar){
            int l = 0,r = nums.size() -1;
            int ans = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(nums[mid] == tar){
                    ans = mid;
                    l = mid+1;
                }
                else if(nums[mid] > tar){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            return ans;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result{-1,1};
        
            result[0] = leftindex(nums,target);
            result[1] = rightindex(nums,target);
        
            return result;
        }
};
