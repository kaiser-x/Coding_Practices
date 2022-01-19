// 63. Unique Paths II
// Medium
// A robot is located at the top-left corner of a m x n 
// grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point 
// in time. The robot is trying to reach the bottom-right 
// corner of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. 
// How many unique paths would there be?

// An obstacle and space is marked as 1 and 0 respectively 
// in the grid.

// Example 1:

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
// Example 2:

// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1
 

 //vis is not needed because we are moving right and down
 //so cycle is not possible
 class Solution {
public:
    //without dp ,tle
    // int ways(vector<vector<int>>& grid,int i,int j,int &m,int &n){
    //     if(i<0||j<0||i>=m||j>=n||grid[i][j]==1) return 0;
    //     if(i==m-1&&j==n-1) return 1;
    //     int right=ways(grid,i,j+1,m,n);
    //     int down=ways(grid,i+1,j,m,n);
    //     return right+down;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     return ways(grid,0,0,m,n);
    // }
    
    //with dp
    
     int ways(vector<vector<int>>& grid,int i,int j,int &m,int &n,vector<vector<int>>&dp){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==1) return 0;
        if(i==m-1&&j==n-1) return 1;
         if(dp[i][j]!=0) return dp[i][j];
        int right=ways(grid,i,j+1,m,n,dp);
        int down=ways(grid,i+1,j,m,n,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        return ways(grid,0,0,m,n,dp);
    }
};