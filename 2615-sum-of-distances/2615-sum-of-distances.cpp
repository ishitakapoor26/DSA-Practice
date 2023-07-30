class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       unordered_map<int,vector<int>> mp;
        vector<long long> res(nums.size(),0);
        for(int i=0;i<nums.size();i++){
                mp[nums[i]].push_back(i);
        }
        for(auto it:mp){
            vector<int> vec=it.second;
            long long sum=0;
            for(auto i:vec) sum+= (long long)i;
            long long currSum=0, restSum=0;
            for(int i=0;i<vec.size();i++){
                restSum= sum-currSum-vec[i];
                long long leftSum= (vec[i]*(long long)i)-currSum;
                long long rightSum= restSum- (vec[i]*(long long)(vec.size()-i-1));
                res[vec[i]]=leftSum+rightSum;
                currSum+=vec[i];
            }
        }
        return res;
    }
};