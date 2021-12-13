//nums has duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[h])
                l=mid+1;
            else if(nums[mid]<nums[h])
                h=mid;
            else
                h--;
        }
        return nums[l];
    }
};