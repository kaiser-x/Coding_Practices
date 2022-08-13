class Solution {
public:
    //now unlike the first search 2d matrix 1 , where it was row wise sorted, and
    // the first element of any row will be greater than the last element of prev row,
    //if exists, so if we consider it as a single array, we can apply
    //binary search, here it is row wise and column wise sorted, so the first and last element
    //thing will not be here, so we only have one way to check in a particular row, from last
    // nad if element is greater than target ,we minimize the col,if element is greater than
    //target we move to the next row, this works bcs matrix is both row and col wise sorted
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        //starting from the first row and last element
        int row=0,col=n-1;
        while(row<m&&col>=0){
            if(mat[row][col]==target) return true;
            else if(mat[row][col]>target) col--;
            else if(mat[row][col]<target) row++;
        }
        return false;
    }
};