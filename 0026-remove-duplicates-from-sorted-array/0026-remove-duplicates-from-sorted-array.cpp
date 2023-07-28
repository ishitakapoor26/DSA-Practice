class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        while(j!=nums.size()){
            if(nums[i]==nums[j]){
                nums.erase(nums.begin()+i);
            }else if(nums[i]!=nums[j]){
                i++;
                j++;
            }
        }
        return nums.size();
    }
};