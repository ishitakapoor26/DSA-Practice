class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
    if (n == 0) return 0;
        int count=0;
        for(int i=0;i<timeSeries.size()-1;i++){
            count+= timeSeries[i+1]-timeSeries[i]<duration ? timeSeries[i+1]-timeSeries[i]: duration;
        }
        return count+duration; 
    }
};