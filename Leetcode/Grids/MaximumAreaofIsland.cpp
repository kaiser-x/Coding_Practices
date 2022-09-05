// 695. Max Area of Island
// Medium
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
// connected 4-directionally (horizontal or vertical.) You may assume all four edges of the
// grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.
// Example 1:
// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:
// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

// CPP CODE:

class Solution {
    
private: 
    vector<vector<int>> dir={{1,0},{0,-1},{0,1},{-1,0}};
    bool isValid(vector<vector<int>>& grid,int i,int j,int  &m,int &n,vector<vector<bool>> &vis){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0||vis[i][j]) return false;
        return true;
    }
    
    int dfs(vector<vector<int>>& grid,int i,int j,int  &m,int &n,vector<vector<bool>> &vis){
        if(!isValid(grid,i,j,m,n,vis)) return 0;
        vis[i][j]=true;
        int area=0;
        for(int x=0;x<4;x++){
                area+=dfs(grid,i+dir[x][0],j+dir[x][1],m,n,vis);
        }
        return area+1;
    }
    
    int bfs(vector<vector<int>>& grid,int i,int j,int  &m,int &n,vector<vector<bool>> &vis){
    queue<pair<int,int>> q;
    int area=0;
    q.push({i,j});
     vis[i][j]=true;
    while(!q.empty()){
        auto p=q.front();
        int r=p.first,c=p.second;
        q.pop();
        area++;
        for(int x=0;x<4;x++){
            int nr=r+dir[x][0],nc=c+dir[x][1];
            if(isValid(grid,nr,nc,m,n,vis)) {
                vis[nr][nc]=true;
                q.push({nr,nc});
            }
        }
    }
    /*Note remember how int dfs if we assign are as 0 then while returning we have to return area+1, 
    the current coordinate is also 1 and we have to add it to the area(number of 1 connected), as when
    we declare sum as0 it means the 1 of the current coordinaate is not counted, so while returning we
    return area+1, but if we intialize area with  1 that means we have counted the 1 of current coordinate
    1 that starts the dfs call, so while return we will return only area
    Now similarly we can do in bfs to but the placing of area ++ will change , lets say if we have declared
    area as 0 then we need to have area++ where we pop the queue front ,and thing, bcs we have not counted
    the coordinates 1 that starts the bfs call, so as we push that coordinate and pop it the first time it
    gets counted, but if we declare area as 1, then we need to have area++ in the for lopp where we
    check validity and insert the coordinate in the queue, bcs the coordinates' 1 that started bfs call
    is counted in area, if we have area++ in where we pop coordinaate, then we will have area 1 extra than
    the actual answer.*/
    return area;
}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),mx=INT_MIN,area=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    // area=dfs(grid,i,j,m,n,vis);
                    area=bfs(grid,i,j,m,n,vis);
                    mx=max(mx,area);
            }
        }
        return mx;
    }
};

// JAVA CODE:

class Solution {
    //we can also change the grid instead of having another visited array.
    static int dir[][]={{1,0},{0,-1},{0,1},{-1,0}};
    static int dfs(int grid[][],int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1) return 0;
        grid[i][j]=-1;
        // return (1+ dfs(grid,i+1,j,m,n)+dfs(grid,i,j-1,m,n)+dfs(grid,i,j+1,m,n)+dfs(grid,i-1,j,m,n));
        // or use the dir array and for loop
        int area=1;
        for(int x=0;x<4;x++){
            int nr=i+dir[x][0],nc=j+dir[x][1];
                area+=dfs(grid,nr,nc,m,n);
        }
        //area is declared as 1 so 1 for the current coordinate is counted so we return area and not area+1
        return area;
    }
    static int bfs(int grid[][],int row,int col,int m,int n){
        Queue<Pair<Integer,Integer>> q=new LinkedList<>();
        q.offer(new Pair(row,col));
        grid[row][col]=-1;
        int area=1;
        while(!q.isEmpty()){
            Pair<Integer,Integer> p=q.poll();
            int i=p.getKey(),j=p.getValue();
            for(int x=0;x<4;x++){
                int nr=i+dir[x][0],nc=j+dir[x][1];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1){
                    grid[nr][nc]=-1;
                    q.offer(new Pair(nr,nc));
                    area++;
                }
            }
        }
    //area is declared as 1 so 1 for the current coordinate is counted so we return area and not area+1
        return area;
    }
    int maxAreaOfIsland(int[][] grid) {
        int m=grid.length,n=grid[0].length;
        int mx=0,area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    // area=dfs(grid,i,j,m,n);
                    area=bfs(grid,i,j,m,n);
                    mx=Math.max(mx,area);
                }
            }
        }
        return mx;
    }
}