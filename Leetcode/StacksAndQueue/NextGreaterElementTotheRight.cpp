// Next Greater Element
// Medium
// Given an array arr[ ] of size N having distinct elements, the task is to find the next 
// greater element for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which 
// is greater than the current element.
// If there does not exist next greater of current element, then next greater element for 
// current element is -1. For example, next greater of the last element is always -1.
// Example 1:
// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element 
// to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
// since it doesn't exist, it is -1.

 vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector< long long> res(n);
        //O(n^2)// will throw tle
        // int i,j;
        // for(i=0;i<n-1;i++){
        //     for(j=i+1;j<n;j++){
        //         if(arr[j]>arr[i]) {
        //             res.push_back(arr[j]); break;
        //         }
        //     }
        //     if(j>=n) res.push_back(-1);
        // }
        // res.push_back(-1);
        // return res;
        stack<long long> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();
            st.push(arr[i]);
        }
        return res;
    }

// Leetcode
// 496. Next Greater Element I
// Easy
// The next greater element of some element x in an array is the first greater element that 
// is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a 
// subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and 
// determine the next greater element of nums2[j] in nums2. If there is no next greater 
// element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element 
// as described above.
// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i]) st.pop();
            if(st.empty()) mp[nums[i]]=-1;
            else mp[nums[i]]=st.top();
            st.push(nums[i]);
        }
        for(int i=0;i<findNums.size();i++) {
          res.push_back(mp[findNums[i]]);
        }
        return res;
    }
};

// Java code:

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int res[]=new int[nums1.length];
        HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>();
        Stack<Integer> st=new Stack<>();
        for(int i=nums2.length-1;i>=0;i--){
            while(!st.isEmpty()&&st.peek()<=nums2[i]) st.pop();
            if(st.isEmpty()) hm.put(nums2[i],-1);
            else hm.put(nums2[i],st.peek());
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.length;i++) res[i]=hm.get(nums1[i]);
        return res;
    }
}