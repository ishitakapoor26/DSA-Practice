class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x, count=0;
        for(int num: nums){
            if(count==0){
                x=num;
            }
            if(num==x){
                count++;
            }else{
                count--;
            }
        }
        return x;
    }
};