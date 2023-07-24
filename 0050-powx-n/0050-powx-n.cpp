class Solution {
public:
    
    double power(double x, long long n){
        if(n==1){
            return x;
        }else if(n==0){
            return 1;
        }else{
            if(n%2==0){
                return power(x*x, n/2);
            }else{
                return x*power(x*x,(n-1)/2);
            }
        }
    }
    
    double myPow(double x, int n) {
        double res;
        if(n>=0){
            res=power(x,(long long) n);
        }else if(n<0){
            res= 1.0/power(x, (long long) -1*n);
        }
        return res;
    }
};