class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=1, high=nums.size()-2, mid;
        if(nums.size()==1){
            return 0;
        }
        else if(nums[0]>nums[1]){
            return 0;
        }else if(nums[high+1]>nums[high]){
            return nums.size()-1;
        }
        while(low<=high){
            mid= low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }else if(nums[mid]>nums[mid+1]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
};