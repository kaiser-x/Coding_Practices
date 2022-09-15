// 73. Set Matrix Zeroes
// Medium
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column 
// to 0's.
// You must do it in place.
// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// Constraints:
// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
// Follow up:
// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
//Cpp Code:

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        /*First approach uses a space of O(m+n), and TC of O(m*n) */
        vector<int> row(m),col(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==1||col[j]==1) mat[i][j]=0;
            }
        }
        
        /*we can optimize the above approach by marking whether the row or col has 0 or not in the 
        matrix's first row and col, but there would be ambiguity as what wil 0,0, the first cell will
        represent, here we have taken it to represent row, so for col we need another indicator so 
        we have taken a bool flag which checks the first column and store true if there exists a 0.
        So now we have to start traversing from 0th row and 1st col, bc 0th col has been already 
        handled, as we traverse if we see any 0 we mark the corrresponding first row and col as 0.*/
        bool flagCol=false;
        for(int i=0;i<m;i++) if(mat[i][0]==0) flagCol=true;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        /*Now we trraverse the cells other than the indicator cells,i.e, we start traversing from 1st
        row and 1st col, bcs we are now changing the value of cell using those indicators cells, so
        for some reason if those first row and col have 0 and whole row and col is changed to 0, then
        using them as indicators whole matrix will become 0,so we handle the first row and col 
        separateley.So as we travers we check if the current i and j has 0 in their corresponding
        mat[i][0]||mat[0][j]. if they do then we set them to 0*/
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][0]==0||mat[0][j]==0) mat[i][j]=0;
            }
        }
        /* As said before the we have taken the first cell as the indicator for the row, so  we check
        if the first cell has 0, if it does it is indicator that their exists a 0 in the row, so we 
        make the whole first row as 0*/
        if(mat[0][0]==0){
            for(int j=0;j<n;j++) mat[0][j]=0;
        }
        /*As said before we have take firsst cell as row indicator ro avoid ambiguity, and had a bool
        variable as indicator for the first col, so we check if it has true value,if it does we change
        the whole column as 0.*/
        if(flagCol){
            for(int i=0;i<m;i++) mat[i][0]=0;
        }
    }
};

//Java Code:

class Solution {
    public void setZeroes(int[][] mat) {
        int m=mat.length,n=mat[0].length;
        boolean flagCol=false;
        for(int i=0;i<m;i++) if(mat[i][0]==0) flagCol=true;
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][0]==0||mat[0][j]==0) mat[i][j]=0;
            }
        }
        if(mat[0][0]==0){
            for(int j=0;j<n;j++) mat[0][j]=0;
        }
        if(flagCol){
            for(int i=0;i<m;i++) mat[i][0]=0;
        }
    }
}