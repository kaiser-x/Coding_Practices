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