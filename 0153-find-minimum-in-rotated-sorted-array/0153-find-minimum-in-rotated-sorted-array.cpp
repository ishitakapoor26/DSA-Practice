class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high= nums.size()-1, mid, ans= nums[0];
        if(nums[low]<nums[high]){
            return nums[low];
        }
        while(low<=high){
            mid= (low+high)/2;
            if(nums[low]<nums[high] && nums[low]<=ans){
                return nums[low];
            }
            ans= min(ans, nums[mid]);
            if(nums[mid]>=nums[low]){
                low= mid+1;
            }else if(nums[mid]<=nums[high]){
                high= mid-1;
            }
        }
        return ans;
    }
};