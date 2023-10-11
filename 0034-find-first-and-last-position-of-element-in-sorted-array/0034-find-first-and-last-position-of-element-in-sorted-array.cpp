class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid, low=0,high=nums.size()-1,i=-1,j=-1;
            while(low<=high){
            mid= low+(high-low)/2;
            if(nums[mid]==target){
                i=j=mid;
                while(i>0 && nums[i-1]==target){   
                    i--;
                }
                while(j<nums.size()-1 && nums[j+1]==target){   
                    j++;
                }
                break;
                
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
            }
        return {i,j};
    }
};