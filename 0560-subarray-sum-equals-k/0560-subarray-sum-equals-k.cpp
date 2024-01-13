class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum=0, cnt=0;
        map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            preSum+= nums[i];
            int remove= preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }
};