class Solution {
public:
    
    int possible(vector<int>& nums, int mid){
        double sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= ceil((double) nums[i]/(double) mid);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
     int low= 1,
        high= *max_element(nums.begin(),nums.end()), mid;
        while(low<=high){
            mid= (low+high)/2;
            if(possible(nums,mid)<=threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};