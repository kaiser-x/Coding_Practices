// 2006. Count Number of Pairs With Absolute Difference K
// Easy
// Given an integer array nums and an integer k, return the 
// number of pairs (i, j) where i < j such 
// that |nums[i] - nums[j]| == k.

// The value of |x| is defined as:

// x if x >= 0.
// -x if x < 0.
 

// Example 1:

// Input: nums = [1,2,2,1], k = 1
// Output: 4
// Explanation: The pairs with an absolute difference 
// of 1 are:
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// Example 2:

// Input: nums = [1,3], k = 3
// Output: 0
// Explanation: There are no pairs with an absolute 
// difference of 3.
// Example 3:

// Input: nums = [3,2,1,5,4], k = 2
// Output: 3
// Explanation: The pairs with an absolute difference of 2 are:
// - [3,2,1,5,4]
// - [3,2,1,5,4]
// - [3,2,1,5,4]
 
// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
// 1 <= k <= 99


class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
     unordered_map<int,int>mp;
      int count=0;
      for(int i=0;i<n;i++){
        //from nums[i] we are checking the numbers with k difference is present
        //in the map and the k value different can be obtained by subtracting k
        //adn add k,e.g nums[i]=20 and k=3,now numbers which have difference 3 with 20 is 
        //17 (20-3) and 23(20+3);
        count+=mp[nums[i]+k]+mp[nums[i]-k];
        mp[nums[i]]++;
      }
      return count;
    }
};