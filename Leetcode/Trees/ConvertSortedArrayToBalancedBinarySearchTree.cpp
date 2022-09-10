// 108. Convert Sorted Array to Binary Search Tree
// Easy
// Given an integer array nums where the elements are sorted in ascending order, 
// convert it to a height-balanced binary search tree.
// A height-balanced binary tree is a binary tree in which the depth of 
// the two subtrees of every node never differs by more than one.
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*this is a simple question but I had to go through stupid amnt of time to solve this,but
    yeah it was worth it, first I figured for any bst to be balanced we need to put,equal 
    number of numbers on both side of a node,so I can just take the fisrt element from array
    and make it aas my root, element,so I thought maybe quicksort partition to find pivot,
    and keep elements smaller on right and greater on right, but the problem is we select 
    an number either element at low or high as pivot and swap contents of elements so
    theres no way we could know which number as pivot will give us equal number of elements
    on both of it side, then I rmeebered its an easy question, the given array is already 
    sorted so obviously the middle element will have smaller elements on left and greater
    elements on right to be equal,so we recursively taake the mid element, create new node
    ,then recursively call the function for low to mid-1 and mid+1 to high and assign them
    to left and right respectivelyy, now the base condition was not clear for me,like whn
    should I stop,I kept pondering then came to solution we need to stop when low crosses 
    high and return NULL*/
    TreeNode* helper(vector<int>&arr,int l,int h,int &n){
        if(l>h) return NULL;
        int mid=l+(h-l)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        //If the single element then jus return the node, but this was also not needed
        //as we are return NULL when ever low or high crosses their respective bounds
        // if(l==h) return root;
        //this one is a tragic mistake,I though after gettin mid element, if their are only
        //2 elements left then just create a tree with those two and just return, but it
        //was a bad idea, fine mid==0 would have worked but mid==n-2 will not, bcs for eg
    //if array size was 3, 3 5 8 and mid was taken ,then remains 1 element on each side,but
        //itll not happe as mid is also equal to n-2 and then it will return 5 null 8
        //instead of 5 3 8, so yeah this if condition was never gonna be base case
        //  if(mid==0||mid==n-2){
        //     root->right=new TreeNode(arr[h]);
        //     return root;
        // }
        root->left=helper(arr,l,mid-1,n);
        root->right=helper(arr,mid+1,h,n);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return new TreeNode(nums[0]);
        return helper(nums,0,n-1,n);
    }
};
//java

class Solution {
    static TreeNode dfs(int []nums,int low,int high){
        if(low>high) return null;
        int mid=low+(high-low)/2;
        TreeNode root=new TreeNode(nums[mid]);
        root.left=dfs(nums,low,mid-1);
        root.right=dfs(nums,mid+1,high);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        int n=nums.length;
        if(n==1) return new TreeNode(nums[0]);
        return dfs(nums,0,n-1);
    }
}