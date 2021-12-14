class Solution {
public:
    int findPeakElement(vector<int>& nums) {
     int n=nums.size()   ;
        int l=0,h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            //check if nums[mid]>nums[mid+1] if it is then theres definitley a peak element on
            // left side inclusive of nums[mid] so high=mid
            if(nums[mid]>nums[mid+1])
                h=mid;
            //if not then theres a peak element difinitely on the right side so,low=mid+1,excluding mid;
            else
                l=mid+1;
        }
        return l;
    }
};