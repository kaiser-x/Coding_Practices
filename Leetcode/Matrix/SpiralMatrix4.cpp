// 2326. Spiral Matrix IV
// Medium
// You are given two integers m and n, which represent the dimensions of a matrix.
// You are also given the head of a linked list of integers.
// Generate an m x n matrix that contains the integers in the linked list presented in 
// spiral order (clockwise), starting from the top-left of the matrix. If there are 
// remaining empty spaces, fill them with -1.
// Return the generated matrix.
// Example 1:
// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// Explanation: The diagram above shows how the values are printed in the matrix.
// Note that the remaining spaces in the matrix are filled with -1.
// Example 2:
// Input: m = 1, n = 4, head = [0,1,2]
// Output: [[0,1,2,-1]]
// Explanation: The diagram above shows how the values are printed from left to right in the matrix.
// The last space in the matrix is set to -1.
// Constraints:
// 1 <= m, n <= 105
// 1 <= m * n <= 105
// The number of nodes in the list is in the range [1, m * n].
// 0 <= Node.val <= 1000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n));
        int top=0,left=0,right=n-1,bottom=m-1,dir=0,k=1;
        while(top<=bottom&&left<=right){
            //left to right, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from top
            if(dir==0){
                for(int i=left;i<=right;i++) {
                    if(head==nullptr) mat[top][i]=-1;
                    else{
                        mat[top][i]=head->val;
                        head=head->next;
                    }
                }
                top++;
                dir=1;
            }
            //top to bottom, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from right
            else if(dir==1){
                for(int i=top;i<=bottom;i++)  {
                    if(head==nullptr) mat[i][right]=-1;
                    else{
                        mat[i][right]=head->val;
                        head=head->next;
                    }
                }
                right--;
                dir=2;
            }
            //right to left, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from bottom
            else if(dir==2){
                for(int i=right;i>=left;i--)  {
                    if(head==nullptr) mat[bottom][i]=-1;
                    else{
                        mat[bottom][i]=head->val;
                        head=head->next;
                    }
                }
                bottom--;
                dir=3;
            }
            //bottom to top, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from left
            else if(dir==3){
                for(int i=bottom;i>=top;i--)  {
                    if(head==nullptr) mat[i][left]=-1;
                    else{
                        mat[i][left]=head->val;
                        head=head->next;
                    }
                }
                left++;
                dir=0;
            }
        }
        return mat;
    }
};

// java

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int mat[][]=new int[m][n];
        int top=0,left=0,right=n-1,bottom=m-1,dir=0,k=1;
        while(top<=bottom&&left<=right){
            //left to right, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from top
            if(dir==0){
                for(int i=left;i<=right;i++) {
                    if(head==null) mat[top][i]=-1;
                    else{
                        mat[top][i]=head.val;
                        head=head.next;
                    }
                }
                top++;
                dir=1;
            }
            //top to bottom, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from right
            else if(dir==1){
                for(int i=top;i<=bottom;i++)  {
                    if(head==null) mat[i][right]=-1;
                    else{
                        mat[i][right]=head.val;
                        head=head.next;
                    }
                }
                right--;
                dir=2;
            }
            //right to left, here row is constant and col change, but how  will we get the row we need
            //to print, we will get it from bottom
            else if(dir==2){
                for(int i=right;i>=left;i--)  {
                    if(head==null) mat[bottom][i]=-1;
                    else{
                        mat[bottom][i]=head.val;
                        head=head.next;
                    }
                }
                bottom--;
                dir=3;
            }
            //bottom to top, here col is constant and row change, but how  will we get the col we need
            //to print, we will get it from left
            else if(dir==3){
                for(int i=bottom;i>=top;i--)  {
                    if(head==null) mat[i][left]=-1;
                    else{
                        mat[i][left]=head.val;
                        head=head.next;
                    }
                }
                left++;
                dir=0;
            }
        }
        return mat;
    }
}