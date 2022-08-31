// 16. 3Sum Closest
// Medium
// Given an integer array nums of length n and an integer target, find three integers 
// in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:
// Input: nums = [0,0,0], target = 1
// Output: 0

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        long long int mx=INT_MIN,mn=INT_MAX;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n-2||i<=n-3){
            int l=i+1,h=n-1;
            while(l<h){
                long long int sum=nums[i]+nums[l]+nums[h];
                if(sum==target) return sum;
                else if(sum<target){
                   mx=max(mx,sum);
                    l++;
                    while(l<h&&nums[l]==nums[l-1]) l++;
                }else {
                    mn=min(mn,sum);
                    h--;
                    while(l<h&&nums[h]==nums[h+1]) h--;
                }
            }
            i++;
            while(i<n-2&&nums[i]==nums[i-1]) i++;
        }
        return (abs(mn-target)<abs(mx-target))? mn:mx;
    }
};