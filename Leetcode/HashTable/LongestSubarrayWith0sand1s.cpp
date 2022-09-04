// 525. Contiguous Array
// Medium
// Given a binary array nums, return the maximum length of a contiguous subarray with an 
// equal number of 0 and 1.
// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 
 class Solution {
public:
    /* So yes Brute force is checking all the sum*/
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) nums[i]=-1;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0) mx=max(mx,i+1);
            else if(mp.find(sum)!=mp.end()) mx=max(mx,i-mp[sum]);
            else mp[sum]=i;
        }
        return mx;
    }
};