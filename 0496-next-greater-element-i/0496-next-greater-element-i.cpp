class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==1 || nums2.size()==1){
            return {-1};
        }
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> ans(nums1.size(),-1);
        for(int num: nums2){
            while(!st.empty() && st.top()<num){
                mp[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){
                ans[i]= mp[nums1[i]];
            }
        }
        return ans;
    }
};