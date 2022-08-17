// 566. Reshape the Matrix
// Easy
// In MATLAB, there is a handy function called reshape which can reshape an m x n matrix 
// into a new one with a different size r x c keeping its original data.
// You are given an m x n matrix mat and two integers r and c representing the number of 
// rows and the number of columns of the wanted reshaped matrix.
// The reshaped matrix should be filled with all the elements of the original matrix in 
// the same row-traversing order as they were.
// If the reshape operation with given parameters is possible and legal, output the new
// reshaped matrix; Otherwise, output the original matrix.



// cpp code:
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int col=mat[0].size(),row=mat.size();
        int numberOfRequiredCells=r*c,numberOfCellsInMat=row*col;
        if((row==r&&col==c)||(numberOfRequiredCells!=numberOfCellsInMat)) return mat;
        int xRow,yCol,matIndex=0;
        vector<vector<int>> res(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                xRow=matIndex/col;
                yCol=matIndex%col;
                res[i][j]=mat[xRow][yCol];
                matIndex++;
            }
        }
        //Now single Loop aproach
		for(int k=0;k<r*c;k++) res[k/c][k%c]=mat[k/col][k%col];
        return res;
    }
};

// java code:

class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int col=mat[0].length,row=mat.length;
        int numberOfRequiredCells=r*c,numberOfCellsInMat=row*col;
        if((row==r&&col==c)||(numberOfRequiredCells!=numberOfCellsInMat)) return mat;
        int xRow,yCol,matIndex=0;
       int res[][]=new int[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                xRow=matIndex/col;
                yCol=matIndex%col;
                res[i][j]=mat[xRow][yCol];
                matIndex++;
            }
        }
        //Now single Loop aproach
		for(int k=0;k<r*c;k++) res[k/c][k%c]=mat[k/col][k%col];
        return res;
    }
}