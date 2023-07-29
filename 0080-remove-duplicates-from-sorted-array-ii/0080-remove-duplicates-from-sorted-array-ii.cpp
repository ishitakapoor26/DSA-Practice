class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int j=1;
        for(int i=2;i<nums.size();i++){
            int currNum= nums[i];
            if(currNum==nums[j] && currNum==nums[j-1])
                continue;
            else{
                nums[++j]=nums[i];
            }
        }
        return j+1;
    }
};