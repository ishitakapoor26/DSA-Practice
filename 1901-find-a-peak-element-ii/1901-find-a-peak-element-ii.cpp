class Solution {
public:
    
    int findMaxIndex(vector<vector<int>> &nums, int n, int m, int col){
        int maxi=-1,idx;
        for(int i=0;i<n;i++){
            if(maxi<nums[i][col]){
                maxi= nums[i][col];
                idx=i;
            }
        }
        return idx;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0, high= mat[0].size()-1;
        int n= mat.size(),m= high+1;
        while(low<=high){
            int mid= (low+high)/2;
            int maxRowIndex= findMaxIndex(mat, n, m, mid);
            int left= mid-1>=0? mat[maxRowIndex][mid-1]:-1;
            int right= mid+1<m? mat[maxRowIndex][mid+1]:-1;
            if(mat[maxRowIndex][mid]>left && mat[maxRowIndex][mid]>right){
                return {maxRowIndex,mid};
            }else if(mat[maxRowIndex][mid]<left){
                high= mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};