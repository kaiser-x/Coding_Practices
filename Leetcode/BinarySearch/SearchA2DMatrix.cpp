// 74. Search a 2D Matrix
// Write an efficient algorithm that searches for a
//  value in an m x n matrix. This matrix has the 
//  following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the 
// last integer of the previous row

// o(log(n)+log(m))
class Solution {    
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();
        if(t<mat[0][0]||t>mat[n-1][m-1]) return false;
        int l=0,h=n-1;
        int row;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mat[mid][0]<=t&&mat[mid][m-1]>=t){
                row=mid;break;
            }
            else if(mat[mid][0]>t) h=mid-1;
            else if(mat[mid][m-1]<t) l=mid+1;
        }
        // cout<<row<<n<<m;
         l=0;h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mat[row][mid]==t) return true;
            else if(mat[row][mid]<t) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};

optimal approach 
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    //in this question it's menttioned that the row is sorted and the first
    //element of any row will be greater than the last element of prev row,
    //if exists, so if we consider it as a single array, we can apply
    //binary search,
     //the idea here i to mark each cell{i.e mat[i][j]} ,as induvidual numbers,
    //for example, if m=3and n=3, it dorm a 3X3 matrix, so we mark each cell
    //of the 9 cells from 0 to 8, 
//     Given Matrix:
//                                         0  1  2
//                                    ---------------
//                                     0 | 1  3  5
//                                     1 | 7  9  10
//                                     2 |12  15 17

// If we convert this to a 1D matrix:

//                         0  1  2  3  4   5   6   7   8 
//                     --------------------------------------
//                          1  3  5  7  9  10  12  15  17
// Here we can see first 3 no. of linear space are 1st row(or total no. of columns)
// Now our task is to map the [row][col] of each matrix with a single integer value, in the above example:
// 1st row:
//                     [0][0] = 0    3*0 + 0 = 0
//                     [0][1] = 1    3*0 + 1 = 1
//                     [0][2] = 2    3*0 + 2 = 2
// So a cell value can be calculated by:
// cell value = Total col * row + col.
// To get the row we’ll divide the cell value by the total column:
// row = cell value / Total col.
// For columns, we have to take the remainder values when an int is divided by the column value.
// col = cell value % Total col.
// Now simply run Binary search algorithm & search the target.
    int low=0,high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int i=mid/n,j=mid%n;
            if(mat[i][j]==target) return true;
            else if(mat[i][j]>target) high=mid-1;
            else low=mid+1;
        }
    return false;
}