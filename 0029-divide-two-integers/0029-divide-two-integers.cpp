class Solution {
public:
    int divide(int dividend, int divisor) {
    if(dividend==divisor) return 1;
    bool sign= dividend>0 == divisor>0;
	unsigned int divid= abs(dividend);
	unsigned int divis= abs(divisor);
	unsigned int res=0;
	while(divid>= divis){
		short q=0;
		while(divid> (divis<<(q+1))) q++;
		res+= 1<<q;
		divid-= divis<<q;
	}
    if(res==(1<<31) && sign) return INT_MAX;
	return sign? res: res*(-1);
    }
};