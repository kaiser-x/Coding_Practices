// 

class Solution {
public:
  //We will use boundary DFS to solve this problem
        
      // Let's analyze when an 'O' cannot be flipped,
      // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
        
      //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '.'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,.,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '.' are elements which cannot be flipped to 'X', so flip them back to 'O'
  
  int dir[4][4]={{1,0},{0,-1},{0,1},{-1,0}};
  //   void dfsForBorderZero(vector<vector<char>>& board,int &m,int &n,int i,int j){
  //     if(i<0||j<0||i>=m||j>=n||board[i][j]=='X'||board[i][j]=='.') return;
  //     board[i][j]='.';
  //     // dfsForBorderZero(board,m,n,i+1,j);
  //     // dfsForBorderZero(board,m,n,i,j-1);
  //     // dfsForBorderZero(board,m,n,i,j+1;
  //     // dfsForBorderZero(board,m,n,i-1,j;
  //     for(int d=0;d<4;d++){
  //        dfsForBorderZero(board,m,n,i+dir[d][0],j+dir[d][1]);
  //     }
  //   }
  //   void solve(vector<vector<char>>& board) {
  //     int m=board.size();
  //     int n=board[0].size();
  //     for(int i=0;i<n;i++)
  //     {
  //       if(board[0][i]=='O') 
  //         dfsForBorderZero(board,m,n,0,i);
  //     }
  //     for(int i=0;i<n;i++)
  //     {
  //       if(board[m-1][i]=='O') 
  //         dfsForBorderZero(board,m,n,m-1,i);
  //     }
  //     for(int i=0;i<m;i++)
  //     {
  //       if(board[i][0]=='O') 
  //         dfsForBorderZero(board,m,n,i,0);
  //     }
  //     for(int i=0;i<m;i++)
  //     {
  //       if(board[i][n-1]=='O') 
  //         dfsForBorderZero(board,m,n,i,n-1);
  //     }
  //     for(int i=0;i<m;i++){
  //       for(int j=0;j<n;j++){
  //         if(board[i][j]=='O')
  //           board[i][j]='X';
  //         else if(board[i][j]=='.')
  //           board[i][j]='O';
  //       }
  //     }
  
  
   //bfs approach
  void bfsForBorderZero(vector<vector<char>>& board,int &m,int &n,int i,int j){
      queue<pair<int,int>>q;
      q.push({i,j});
      board[i][j]='.';
     while(!q.empty()){
       pair<int,int>p =q.front();
       q.pop();
       int x,y;
        for(int d=0;d<4;d++){
          x=p.first+dir[d][0];y=p.second+dir[d][1];
          if(x<0||y<0||x>=m||y>=n||board[x][y]=='X'||board[x][y]=='.') 
            continue;
          q.push({x,y});
          board[x][y]='.';
        }
     }
    }
      void solve(vector<vector<char>>& board) {
      int m=board.size();
      int n=board[0].size();
      for(int i=0;i<n;i++)
      {
        if(board[0][i]=='O') 
          bfsForBorderZero(board,m,n,0,i);
      }
      for(int i=0;i<n;i++)
      {
        if(board[m-1][i]=='O') 
          bfsForBorderZero(board,m,n,m-1,i);
      }
      for(int i=0;i<m;i++)
      {
        if(board[i][0]=='O') 
          bfsForBorderZero(board,m,n,i,0);
      }
      for(int i=0;i<m;i++)
      {
        if(board[i][n-1]=='O') 
          bfsForBorderZero(board,m,n,i,n-1);
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(board[i][j]=='O')
            board[i][j]='X';
          else if(board[i][j]=='.')
            board[i][j]='O';
        }
      }
        
   
  }    
};