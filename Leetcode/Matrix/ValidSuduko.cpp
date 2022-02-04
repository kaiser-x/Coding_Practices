// 36. Valid Sudoku
// Medium
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be 
// validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
// Example 1:
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner 
// being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
// Constraints:
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.

class Solution {
public:
    //the idea here is simple ,i took the isValid funtion from
    //suduko solver, so I am traversing all,if it is a non empty  cell
    //i am checking if it is valid or not,if not return false.
    //if traverse all cells and reached n,n then return true,as there
    //are no invalid cell.
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     for(int i=0;i<9;i++){
    //         for(int j=0;j<9;j++){
    //             if(board[i][j]!='.'){
    //                 if((isValid(board,i,j,board[i][j])==false)) return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    //valid section takes row and col,check if its valid in that row,in that
    //col and in that 3X3 box,what I did wrong at first was, i made the function ,but I forgot that
    //the all if conditions check all the cells in that sub,so eventuall the board[row][col]
    //will also be checked and then it will return false,so we need to neglect that row,col cel;
    //in all three checks,adn if traverse return truee.
    // bool isValid(vector<vector<char>>&board,int row,int col,char ch){
    //     for(int i=0;i<9;i++){
    //         if(board[i][col]==ch&&i!=row) return false;
    //         if(board[row][i]==ch&&i!=col) return false;
    //         int x=3*(row/3)+i/3,y=3*(col/3)+i%3;
    //         if(board[x][y]==ch&&x!=row&&y!=col) return false;
    //     }
    //     return true;
    // }
    //Now the more optimal way would be to use a hash and store 1 if that num is used and 0 if not
    /* So how the hash works is we 9 rows and 9 col line then 9 3X3 sub boxes
    hashRow[9][10],hashCol[9][10] and hashQuadrant[9][10] ,so here the first 9 represents each
    9 rows,cols and quadrants respectively, then 10 is for the number , finding the row and col is 
    easy as we would be traversing using two loops i and i, i will be row and j will be col
    ,the problem is with findin which quadrant does the row,col belongs to, for that we need to have 
    a formula, k=3*i/3+j/3, check ifhash has 1 for any cell,if yes return false,else mark the hashes as
    1 and continue traversal,i reached n,n return true */
     bool isValidSudoku(vector<vector<char>>& board) {
         vector<vector<int>>hashRow(9,vector<int>(10,0));
         vector<vector<int>>hashCol(9,vector<int>(10,0));
         vector<vector<int>>hashQuadrant(9,vector<int>(10,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    if(hashRow[i][num]==1||hashCol[j][num]==1||hashQuadrant[3*(i/3)+j/3][num]==1) 
                        return false;
                    hashRow[i][num]=1;hashCol[j][num]=1;hashQuadrant[3*(i/3)+j/3][num]=1;
                }
            }
        }
        return true;
    }
    //instead of hash like vetor you can also use set which returns false if you try to insert
    //a thing which is already present,make set of string, add to set like, num in i row
    //num in j col and num in 3*(i/3)+j/3 quadrant, before adding check if it these strings 
    //present in t
};