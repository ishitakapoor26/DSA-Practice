
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> length(nums.size(),1);
        vector<int> count(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(length[j]+1>length[i]){
                        length[i]=length[j]+1;
                        count[i]=0;
                    }
                    if(length[j]+1==length[i]){
                        count[i]+=count[j];
                    }
                }
            }
        }
        int result=0;
        int maxLength= *max_element(length.begin(),length.end());
        for(int i=0;i<nums.size();i++){
            if(length[i]==maxLength){
                result+=count[i];
            } 
        }
        return result;
    }
};