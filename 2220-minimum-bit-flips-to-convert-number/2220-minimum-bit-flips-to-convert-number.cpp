class Solution {
public:
    int minBitFlips(int a, int b) {
    if(a==b) return 0;
    int cnt=0;
    while(b|a){
        if((a&1)!=(b&1)){
            cnt++;
        }
        a>>=1;
        b>>=1;
    }
    return cnt;
    }
};