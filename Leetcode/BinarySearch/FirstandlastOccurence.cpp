// 34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n=nums.size();
        int l=0,h=n-1;
        int first=-1,last=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                first=mid;
                h=mid-1;
                continue;
            }
            if(nums[mid]<target)
                l=mid+1;
            else
                h=mid-1;
        }
        l=0;h=n-1;
         while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                last=mid;
                l=mid+1;
                continue;
            }
            if(nums[mid]<target)
                l=mid+1;
            else
                h=mid-1;
        }
        res.push_back(first);
        res.push_back(last);
        return res;
        
    }
};