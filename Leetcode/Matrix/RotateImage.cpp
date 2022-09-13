// 48. Rotate Image
// Medium
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees 
// (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix 
// directly. DO NOT allocate another 2D matrix and do the rotation.
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        //take a transpose 
        for(int i=0;i<m;i++){
            for(int j=i+1;j<n;j++)
                swap(mat[i][j],mat[j][i]);
        }
        //reverse each row.
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};