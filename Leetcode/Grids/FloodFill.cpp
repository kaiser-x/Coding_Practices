// 733. Flood Fill
// Easy
// An image is represented by an m x n integer grid image where image[i][j]
// represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a 
// flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels 
// connected 4-directionally to the starting pixel of the same color as the 
// starting pixel, plus any pixels connected 4-directionally to those 
// pixels (also with the same color), and so on. Replace the color of all 
// of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.


class Solution {
    /*Simple DFS and BFS approach */
private:
vector<vector<int>> dir={{1,0},{0,-1},{0,1},{-1,0}};
void dfs(vector<vector<int>>& image,int i,int j,int &m,int &n,int &color,int &existingColor){
        if(i<0||j<0||i>=m||j>=n||image[i][j]==color||image[i][j]!=existingColor) 
            return;
        image[i][j]=color;
        for(int x=0;x<4;x++){
            dfs(image,i+dir[x][0],j+dir[x][1],m,n,color,existingColor);
        }
}
bool isValid(vector<vector<int>>&image,int i,int j,int &m,int &n,int &color,int existingColor){
        if(i<0||j<0||i>=m||j>=n||image[i][j]==color||image[i][j]!=existingColor) 
            return false;
        return true;
    }
void bfs(vector<vector<int>>& image,int i,int j,int &m,int &n,int &color,int &existingColor){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
        
                auto p=q.front();
                q.pop();
                for(int x=0;x<4;x++){
            if(isValid(image,p.first+dir[x][0],p.second+dir[x][1],m,n,color,existingColor))
                q.push({p.first+dir[x][0],p.second+dir[x][1]});
                }
                image[p.first][p.second]=color;

        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size(),existingColor=image[sr][sc];
        if(existingColor==color) return image;
        // dfs(image,sr,sc,m,n,color,existingColor);
        bfs(image,sr,sc,m,n,color,existingColor);
        return image;
    }
};

class Solution {
    static void dfs(int [][]image,int i,int j,int m,int n,int color,int existingColor){
        if(i<0||j<0||i>=m||j>=n||image[i][j]==color||image[i][j]!=existingColor) return;
        image[i][j]=color;
        dfs(image,i+1,j,m,n,color,existingColor);
        dfs(image,i,j-1,m,n,color,existingColor);
        dfs(image,i,j+1,m,n,color,existingColor);
        dfs(image,i-1,j,m,n,color,existingColor);
        return;
    }
    static boolean isValid(int [][]image,int i,int j,int m,int n,int color,int existingColor){
      if(i<0||j<0||i>=m||j>=n||image[i][j]==color||image[i][j]!=existingColor) return false; 
        return true;
    }
    static void bfs(int [][]image,int i,int j,int m,int n,int color,int existingColor){
        Queue<Pair<Integer,Integer>> q=new LinkedList<>();
        q.add(new Pair(i,j));
        while(!q.isEmpty()){
                Pair<Integer,Integer> p=q.poll();
                if(isValid(image,p.getKey()+1,p.getValue(),m,n,color,existingColor))
                    q.add(new Pair(p.getKey()+1,p.getValue()));
                 if(isValid(image,p.getKey(),p.getValue()-1,m,n,color,existingColor))
                    q.add(new Pair(p.getKey(),p.getValue()-1));
                 if(isValid(image,p.getKey(),p.getValue()+1,m,n,color,existingColor))
                    q.add(new Pair(p.getKey(),p.getValue()+1));
                 if(isValid(image,p.getKey()-1,p.getValue(),m,n,color,existingColor))
                    q.add(new Pair(p.getKey()-1,p.getValue()));
                image[p.getKey()][p.getValue()]=color;
            
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int m=image.length,n=image[0].length,existingColor=image[sr][sc];
        if(existingColor==color) return image;
        // dfs(image,sr,sc,m,n,color,existingColor);
        bfs(image,sr,sc,m,n,color,existingColor);
        return image;
    }
}