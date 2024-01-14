class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        if(s.length()==1) return mp[s[0]];
        int i=0;
        while(i<s.length()-1){
            if(mp[s[i]]>=mp[s[i+1]]){
                sum+= mp[s[i]];
                i++;
            } 
            else{
                sum+= mp[s[i+1]]-mp[s[i]];
                i+=2;
            }
        }
        if(i<s.length()){
        if(mp[s[i-1]]>=mp[s[i]]){
                sum+= mp[s[i]];
                i++;
            } 
            else{
                sum+= mp[s[i]]-mp[s[i-1]];
                i+=2;
            }
        }
        return sum;
    }
};