// 54. Spiral Matrix
// Medium
// Given an m x n matrix, return all elements of the matrix in spiral order.
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

// Cpp code:

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        int m=mat.size(),n=mat[0].size();
        vector<int> res(m*n);
        int top=0,left=0,right=n-1,bottom=m-1,dir=0,k=0;
        while(top<=bottom&&left<=right){
            //left to right, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from top
            if(dir==0){
                for(int i=left;i<=right;i++) res[k++]=mat[top][i];
                top++;
                dir=1;
            }
            //top to bottom, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from right
            else if(dir==1){
                for(int i=top;i<=bottom;i++) res[k++]=mat[i][right];
                right--;
                dir=2;
            }
            //right to left, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from bottom
            else if(dir==2){
                for(int i=right;i>=left;i--) res[k++]=mat[bottom][i];
                bottom--;
                dir=3;
            }
            //bottom to top, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from left
            else if(dir==3){
                for(int i=bottom;i>=top;i--) res[k++]=mat[i][left];
                left++;
                dir=0;
            }
        }
        return res;
    }
};

// Java Code:

class Solution {
    public List<Integer> spiralOrder(int[][] mat) {
        int m=mat.length,n=mat[0].length;
        List<Integer> res=new ArrayList<>();
        int top=0,left=0,right=n-1,bottom=m-1,dir=0,k=0;
        while(top<=bottom&&left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++) res.add(mat[top][i]);
                top++;
                dir=1;
            }else if(dir==1){
                for(int i=top;i<=bottom;i++) res.add(mat[i][right]);
                right--;
                dir=2;
            }else if(dir==2){
                for(int i=right;i>=left;i--) res.add(mat[bottom][i]);
                bottom--;
                dir=3;
            }else if(dir==3){
                for(int i=bottom;i>=top;i--) res.add(mat[i][left]);
                left++;
                dir=0;
            }
        }
        return res;
    }
}