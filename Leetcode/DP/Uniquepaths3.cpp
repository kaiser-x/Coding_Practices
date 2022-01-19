// 980. Unique Paths III
// Hard
// You are given an m x n integer array grid where 
// grid[i][j] could be:

// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting 
// square to the ending square, that walk over every non-obstacle 
// square exactly once.

// Example 1:

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:

// Input: grid = [[0,1],[2,0]]
// Output: 0
// Explanation: There is no path that walks over every empty 
// square exactly once.
// Note that the starting and ending square can be anywhere in the grid.
class Solution {
public:
    //unlike prev unique path questions ,here we have to use vis array 
    //as we want to use a square exactly once and also becuase 
    //its four direction so cycle is possible
    //without dp no tle
    int ways(vector<vector<int>>& grid,int i,int j,int &m,int &n,vector<vector<bool>>&vis,int &ei,int &ej,int steps,int&totalZero){
        if(i<0||j<0||i>=m||j>=n||vis[i][j]||grid[i][j]==-1) return 0;
        if(i==ei&&j==ej){
            if(steps==totalZero)
                return 1;
            return 0;
        }
        vis[i][j]=true;
        int count=ways(grid,i+1,j,m,n,vis,ei,ej,steps+1,totalZero)+
    ways(grid,i,j+1,m,n,vis,ei,ej,steps+1,totalZero)+
    ways(grid,i-1,j,m,n,vis,ei,ej,steps+1,totalZero)+
    ways(grid,i,j-1,m,n,vis,ei,ej,steps+1,totalZero);
        vis[i][j]=false;
        return count;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int si,sj,ei,ej,totalZero=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    si=i;sj=j;
                }else if(grid[i][j]==2){
                    ei=i;ej=j;
                    totalZero++;
                }else if(grid[i][j]==0) totalZero++;
            }
        }
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        return ways(grid,si,sj,m,n,vis,ei,ej,0,totalZero);
    }
    
    //with dp did not work idk why.
//      int ways(vector<vector<int>>& grid,int i,int j,int &m,int &n,vector<vector<bool>>&vis,int &ei,int &ej,int steps,int&totalZero,vector<vector<int>>&dp){
//         if(i<0||j<0||i>=m||j>=n||vis[i][j]||grid[i][j]==-1) return 0;
//          if(dp[i][j]!=0) return dp[i][j];
//         if(i==ei&&j==ej){
//             if(steps==totalZero)
//                 return 1;
//             return 0;
//         }
        
//         vis[i][j]=true;
//         int count=ways(grid,i+1,j,m,n,vis,ei,ej,steps+1,totalZero,dp)+
//             ways(grid,i,j+1,m,n,vis,ei,ej,steps+1,totalZero,dp)+
//             ways(grid,i-1,j,m,n,vis,ei,ej,steps+1,totalZero,dp)+
//             ways(grid,i,j-1,m,n,vis,ei,ej,steps+1,totalZero,dp);
         
//         vis[i][j]=false;
//         return dp[i][j]=count;
//     }
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int si,sj,ei,ej,totalZero=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     si=i;sj=j;
//                 }else if(grid[i][j]==2){
//                     ei=i;ej=j;
//                     totalZero++;
//                 }else if(grid[i][j]==0) totalZero++;
//             }
//         }
//         vector<vector<bool>>vis(m,vector<bool>(n,false));
//         vector<vector<int>>dp(m,vector<int>(n,0));
//         return ways(grid,si,sj,m,n,vis,ei,ej,0,totalZero,dp);
//     }
};