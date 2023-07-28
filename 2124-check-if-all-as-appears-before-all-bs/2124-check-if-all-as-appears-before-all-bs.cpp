class Solution {
public:
    bool checkString(string s) {
     int i=0,j=1;
        while(j<s.length()){
            if(s[i]==s[j]){
                j++;
            }else if (s[i]!=s[j] && s[j-1]=='a'){
                i=j;
                j++;
            }else{
                return false;
            }
        }
        return true;
    }
};