class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                swap(nums[low],nums[i]);
                low++;
            }
        }
        for(int i=low;i<nums.size();i++){
            if(nums[i]==1){
                swap(nums[low],nums[i]);
                low++;
            }
        }
    }
};