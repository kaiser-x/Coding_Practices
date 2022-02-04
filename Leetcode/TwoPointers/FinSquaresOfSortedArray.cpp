// 977. Squares of a Sorted Array
// Easy

// Given an integer array nums sorted in non-decreasing order, 
// return an array of the squares of each number sorted in non-decreasing order.
// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*so the  brute would be caluculating all the squares ,storing them in 
         a vector and then sorting the array,but as the array given is sorted so we
         have to option either binary search or two pointer,and here obviously two pointer
         is gonna work,so the idea is at every position ,let it be start or end,we 
         now that element has the chance of being the highest element ,because square of 
         a -ve number is positive and square of +ve is bigger +ve number, so at each
         iteration we check the start and end elements,but instead of calculatin squares and 
         comparing the numbers we just take the abs,obviousl the greater abs'ed number will
         have greater square value and it will be needed to be pushed at the end of result
         vector,now next iteration compare start and end adn fill the second highest value
         and so on ,till i and j dont cross each other*/
        
        //the main intution is , start and end elements can only compete for
        //highest value and abs is better than taking square of each number and comparing
        int n=nums.size();
        vector<int> res(n);
        int i=0,j=n-1,k=n;
        while(i<=j){
            if(abs(nums[i])>=abs(nums[j])){
                res[--k]=nums[i]*nums[i];
                i++;
            }else {
                res[--k]=nums[j]*nums[j];
                j--;
            }
        }
        //this does the same
        //  for(int k=h;k>=0;k--)
        // {
        //     res[k]=(abs(nums[i])>abs(nums[h]))?nums[i]*nums[i++]:nums[h]*nums[h--];
        // }
        return res;
    }
};