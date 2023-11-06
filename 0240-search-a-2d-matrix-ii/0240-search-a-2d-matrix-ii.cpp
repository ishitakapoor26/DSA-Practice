class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res=false;
        int row=0,col= matrix[0].size()-1;
        while(row<matrix.size() && col<matrix[0].size()){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                row++;
            }else{
                col--;
            }
        }
        return false;
    }
};