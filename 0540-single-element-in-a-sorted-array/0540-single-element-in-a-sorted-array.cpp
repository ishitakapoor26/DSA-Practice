class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0, high= nums.size()-1, mid;
        while(low<high){
            mid= low+(high-low)/2;
            if(nums[mid]==nums[mid-1] || nums[mid]==nums[mid+1]){
                if(nums[low]==nums[low+1]){
                    low+=2;
                }else if(nums[high]==nums[high-1]){
                    high-=2;
                }
            }else{
                return nums[mid];
            }
        }
        return nums[low];
    }
};