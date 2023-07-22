class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1){
            return;
        }
        int i=0, n= nums.size();
        while(i<nums.size()){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
            }else{
                i++;
            }
        }
        for(int j=0;j<n-i;j++){
            nums.push_back(0);
        }
    }
};