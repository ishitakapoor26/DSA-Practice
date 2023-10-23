class Solution {
public:
    
    int maximum(vector<int> arr){
        int maxN= INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxN= max(arr[i], maxN);
        }
        return maxN;
    }
    
    double func(vector<int> arr, int hour){
        double hrs=0;
        for(int i=0;i<=arr.size()-1;i++){
            hrs+= ceil((double)arr[i]/(double)hour);
        }
        return hrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid, low=1, high= maximum(piles);
        while(low<=high){
            mid= (low+high)/2;
            if(func(piles, mid)<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};