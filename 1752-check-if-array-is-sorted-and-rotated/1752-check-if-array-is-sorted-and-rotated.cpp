class Solution {
public:
    bool check(vector<int>& nums) {
        int x=0;
        bool flag=false;
        vector<int> A=nums;
        sort(nums.begin(),nums.end());
        while(x<nums.size()){
            for(int i=0;i<nums.size();i++){
                if(A[i]==nums[(i+x)%A.size()]){
                    flag=true;
                }else{
                    flag=false;
                    break;
                }
            }
            x++;
            if(flag){
                return true;
            }
        }
        return false;
    }
};