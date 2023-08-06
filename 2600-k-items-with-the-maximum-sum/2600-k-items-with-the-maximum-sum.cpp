class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum=0;
        while(k>0){
            if(numOnes>0){
                numOnes--;
                sum+=1;
                k--;
            }else if(numZeros>0){
                numZeros--;
                sum+=0;
                k--;
            }else if(numNegOnes>0){
                numNegOnes--;
                sum+=-1;
                k--;
            }
        }
        return sum;
    }
};