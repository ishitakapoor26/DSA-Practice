class Solution {
public:
    
    bool searchElement(vector<int> nums, int target){
        int low=0, high= nums.size()-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high= mid-1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res=false;
        for(auto nums: matrix){
            res= searchElement(nums,target);
            if(res) return true;
        }
        return false;
    }
};