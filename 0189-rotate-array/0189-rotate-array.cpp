class Solution {
public:
    
    void reverse(vector<int>& nums, int l, int h){
        while(l<h){
            swap(nums[l],nums[h]);
            l++;
            h--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
};