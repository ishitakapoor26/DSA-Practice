class Solution {
public:
    bool judgeCircle(string moves) {
     int xcount=0, ycount=0;
        unordered_map<char, int> mp;
        mp['R']=1;
        mp['L']=-1;
        mp['U']=1;
        mp['D']=-1;
        for(char i : moves){
            if(i=='U'  || i=='D'){
                ycount+=mp[i];
            }else if(i=='L' || i=='R'){
                xcount+= mp[i];   
            }
        }
        return xcount==0 && ycount==0?true:false;
    }
};