class Solution {
public:
    
    int func(vector<int> &nums, int mid){
        int sNum=1, splitSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+splitSum<=mid) splitSum+= nums[i];
            else{
                sNum++;
                splitSum= nums[i];
            }
        }
        return sNum;
    }
    
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k){
            return -1;
        }
        int low= *max_element(nums.begin(),nums.end()),
        high= accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid= (low+high)/2;
            int splitNumber= func(nums,mid);
            if(splitNumber>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};