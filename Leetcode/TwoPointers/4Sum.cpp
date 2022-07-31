// 18. 4Sum
// Medium

// Given an array nums of n integers, return an array of all the unique quadruplets 
// [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

class Solution {
public:
    //So the brute force would be sort and use 3 loops i,j and k, and binary search for the last
    //element ,it'd beO(n3 * logn) + O(logm) for storing the elements in set for
    //unique quadrapules, I aint gonn do it,as it is clear from approach
    
    
    //but the optiml would be to use 2 loops i and j and apply two pointer for rest two elements
    //which sould all sum up to target
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        // for(auto i:nums) cout<<i<<" ";
        int i=0,j,l,h,n=nums.size(),target2;
        //why n-3? well its quadruplets ,so we need to iterate i
        //till last windows starin point,for 3 sum its n-2
        while(i<n-3){
            j=i+1;
            //n-2 because its ahead of i and always will and its second
            //elemnt for the last window of size 4,similar to 3sum
            while(j<n-2){
                //toavoid overlfow while adding,we are suntracting 
                //from target and saving it in target2
               target2=target-(nums[i]+nums[j]);
                l=j+1;h=n-1;
                while(l<h){
                    int sumRight=nums[l]+nums[h];
                    if(sumRight==target2){
                        res.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++;h--;
                        while(l<h&&nums[l]==nums[l-1]) l++;
                        while(l<h&&nums[h]==nums[h+1]) h--;
                    }
                    else if(sumRight<target2) l++;
                    else if(sumRight>target2) h--;
                }
                j++;
                while(j<n-2&&nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<n-3&&nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};