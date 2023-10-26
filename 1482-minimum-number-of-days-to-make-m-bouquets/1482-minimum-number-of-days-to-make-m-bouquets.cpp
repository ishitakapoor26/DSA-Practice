class Solution {
public:
    int func(vector<int> bloomDay, int k, int mid)
{
    int count=0, tot=0;
    for(int i=0;i<bloomDay.size();i++)
    {
        if(bloomDay[i]<=mid)
        {
            count++;
            if(count==k)
            {
                tot++;
                count=0;
            }
        }else
        count=0;
    }
    return tot;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m>bloomDay.size()/k) 
        return -1;
        int low =*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(func(bloomDay,k,mid)>=m)
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};