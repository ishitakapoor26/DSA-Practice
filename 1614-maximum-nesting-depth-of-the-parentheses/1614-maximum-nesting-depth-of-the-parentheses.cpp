class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int res=0;
        for(auto i:s){
            if(i=='(') cnt++;
            else if(i==')') cnt--;
            res= max(cnt,res);
        }
        return res;
    }
};