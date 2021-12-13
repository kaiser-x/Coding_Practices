// 153. Find Minimum in Rotated Sorted Array,nums doesn't have duplicates,its unique
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[h])
               l=mid+1;
            else
                h=mid;
        }
        return nums[l];
    }
};