// 503. Next Greater Element II
// Medium
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is 
// nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order 
// next in the array, which means you could search circularly to find its next greater number. 
// If it doesn't exist, return -1 for this number.
// Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        stack<int> st;
        //the idea is to exactly copy the array twice, so that we can get the next greater for the lase
        //element in a circular manner, but theres another way of using modulus operator, and we can still
        //use the given array without creating any copy, how to do that, same as earlier nge question
        //we start from n-1, but here we start from 2n-1 and every where we usse i we will change it to
        //i%n, then whenver i is less than n we will start inserting in given vector.
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i%n]) st.pop();
            //we proces res vector only when i<n, bcs that sub array will have all ans, and the other
        //n to 2n-1 will have answers butt then again for few elements will notand we will need to circle
            //again and it will be infinit, so we juts use 0 to n-1 subbarray which will eventually have all
            //crct nge
            if(i<n){
                if(st.empty()) res[i]=-1;
                else res[i]=st.top();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
};

// Java code:

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int res[]=new int[n];
        Stack<Integer> st=new Stack<Integer>();
        for(int i=2*n-1;i>=0;i--){
            while(!st.isEmpty()&&st.peek()<=nums[i%n]) st.pop();
            if(i<n){
                if(st.isEmpty()) res[i]=-1;
                else res[i]=st.peek();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
}