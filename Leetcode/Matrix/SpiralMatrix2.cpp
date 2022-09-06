// 59. Spiral Matrix II
// Medium
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to 
// n2 in spiral order.
// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        int top=0,left=0,right=n-1,bottom=n-1,dir=0,k=1;
        while(k<=n*n){
            //left to right, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from top
            if(dir==0){
                for(int i=left;i<=right;i++) mat[top][i]=k++;;
                top++;
                dir=1;
            }
            //top to bottom, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from right
            else if(dir==1){
                for(int i=top;i<=bottom;i++) mat[i][right]=k++;
                right--;
                dir=2;
            }
            //right to left, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from bottom
            else if(dir==2){
                for(int i=right;i>=left;i--) mat[bottom][i]=k++;
                bottom--;
                dir=3;
            }
            //bottom to top, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from left
            else if(dir==3){
                for(int i=bottom;i>=top;i--) mat[i][left]=k++;
                left++;
                dir=0;
            }
        }
        return mat;
    }
};

// java code
class Solution {
    public int[][] generateMatrix(int n) {
            int mat[][]=new int[n][n];
        int top=0,left=0,right=n-1,bottom=n-1,dir=0,k=1;
        while(k<=n*n){
            //left to right, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from top
            if(dir==0){
                for(int i=left;i<=right;i++) mat[top][i]=k++;;
                top++;
                dir=1;
            }
            //top to bottom, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from right
            else if(dir==1){
                for(int i=top;i<=bottom;i++) mat[i][right]=k++;
                right--;
                dir=2;
            }
            //right to left, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from bottom
            else if(dir==2){
                for(int i=right;i>=left;i--) mat[bottom][i]=k++;
                bottom--;
                dir=3;
            }
            //bottom to top, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from left
            else if(dir==3){
                for(int i=bottom;i>=top;i--) mat[i][left]=k++;
                left++;
                dir=0;
            }
        }
        return mat;
    }
}