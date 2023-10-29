class Solution {
public:
    
    int func(vector<int>& weights, int cap){
    int load=0, days=1;
        for(int i=0;i<weights.size();i++){
            if(load+ weights[i]>cap){
                load=weights[i];
                days+=1;
            }else{
                load+=weights[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid= (low+high)/2;
            int nod= func(weights, mid);
            if(nod<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};