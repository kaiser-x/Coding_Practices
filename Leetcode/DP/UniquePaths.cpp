// 62. Unique Paths
// Medium

// There is a robot on an m x n grid. 
// The robot is initially located at the top-left corner 
// (i.e., grid[0][0]). The robot tries to move to the 
// bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at 
// any point in time.

// Given the two integers m and n, return the number 
// of possible unique paths that the robot can take 
// to reach the bottom-right corner.

// The test cases are generated so that the answer will
// be less than or equal to 2 * 109.

// Example 1:

// Input: m = 3, n = 7
// Output: 28

 //vis is not needed because we are moving right and down
 //so cycle is not possible

class Solution {
public:
    //without dp,tle
    // int ways(int i,int j,int m,int n,vector<vector<int>>&dp){
    //     if(i<0||i>=m||j<0||j>=n) return 0;
    //     if(i==m-1&&j==n-1) return 1;
    //     int right=ways(i,j+1,m,n);
    //     int down=ways(i+1,j,m,n);
    //     return right+down;
    // }
    // int uniquePaths(int m, int n) {
    //     return ways(0,0,m,n);
    // }

    //with dp
    int ways(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i<0||i>=m||j<0||j>=n) return 0;
        if(i==m-1&&j==n-1) return 1;
        if(dp[i][j]!=0) return dp[i][j];
        int right=ways(i,j+1,m,n,dp);
        int down=ways(i+1,j,m,n,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return ways(0,0,m,n,dp);
    }
};