// 37. Sudoku Solver
// Hard
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.
// Example 1:
// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:
// Constraints:
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //the idea is to traerse find empty spot,then try all numbers from
        //1 to 9,if its valid, mark the number on board and find the
        //next empty cell,if its is not valid ,try next number,if all 9
        //numbers failed then return false,if returned false while backtracking
        //change the previously marked cell back to empty.
        /* So 1) traverse and check if a cell is empty
        2)now for that empty cell try to fill all numbers from 1 to 9,
        3) Check if the number is valid for that row or not, if it is valid
        then fill the cell with that number and do the recursive call further
        4) Now since it's a 9X9 matrix and further mpre 9 chances to be filled
        in an empty celll the complexity is high,so there exists only one solution
        so if we find that ssolution we just return true,so the next recursive call is placed
        inside a IF and if it's true the return true ,no further recursive call is needed
        5) what if all the 9 numbers fail at an empty cell,we return false,and the control goes
        to previous call,where there would be a else after the recursive call in IF
        that empties the already filled cell(as that number does not yield true
        6) similaryly if we the two for loops reach n we just return true*/
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        //traversing board to find empty cell
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                //'. represents empty cell'
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isValid(board,i,j,k+'0')){
                            board[i][j]=k+'0';
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    //valid check,row and coll are understandable,but the check for 
    //ch in 3X3 box is wierd , 9 is divided into 3 parts,
    //the 3*(row/3) or 3(col/3) is to find out in which 
    // part does the row and col lie both row and col wise respectively
    //now we found the starting lets say x,y of the part that the row
    //coll lies,now we check the whole 3 X 3 box,for that i/3 and i%3 
    //is added,i/3 change after every multiple of 3 and i%3 changes at every
    //increement,so the control goes columnwise check for a row
    //then change row,vice versa is also possible,no matter which methos
    //you follow you just need to check for ch in that 3X3 box;
    bool isValid(vector<vector<char>>& board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
            if(board[row][i]==ch) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch)  return false;
        }
        //if no if matched ,then that cell is valid and no
        //constraints are broke,so return true
        return true;
    }
};