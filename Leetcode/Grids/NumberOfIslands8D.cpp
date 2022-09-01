// Find the number of islands
// Medium
// This problem is part of GFG SDE Sheet. Click here to view more.  
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the 
// grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands 
// horizontally or vertically or diagonally i.e., in all 8 directions.
// Example 1:
// Input:
// grid = {{0,1},{1,0},{1,1},{1,0}}
// Output:
// 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.

//we know the dfs approach,heres the bfs approach

vector<vector<int>> dir={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    void bfs(vector<vector<char>> &grid,int i,int j,int &n,int &m){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            for(int x=0;x<8;x++){
                int nr=ele.first+dir[x][0],nc=ele.second+dir[x][1];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]!='0'&&grid[nr][nc]!='.'){
                    q.push({nr,nc});
                    grid[nr][nc]='.';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j,n,m);
                    res++;
                }
            }
        }
        return res;
        
    }