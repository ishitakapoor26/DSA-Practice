class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r= height.size()-1;
        int leftmax=0, rightmax=0;
        int res=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=leftmax) leftmax=height[l];
                else res+= leftmax-height[l];
                l++;
            }else if(height[l]>height[r]){
                if(height[r]>=rightmax) rightmax=height[r];
                else res+= rightmax-height[r];
                r--;
            }
        }
        return res;
    }
};