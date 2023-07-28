class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                j++;
            }else{
                count=max(count,j);
                j=0;
            }
        }
        return max(count,j);
    }
};