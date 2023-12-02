class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int calc=0;
    for(int i=0;i<nums.size();i++){
        calc= calc^nums[i];
    }
    return calc;
    }
};