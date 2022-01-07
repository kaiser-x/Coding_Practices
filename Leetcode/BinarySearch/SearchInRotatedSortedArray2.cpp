//with duplicaates
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[l]){
                if(target>=nums[l]&&target<=nums[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else if(nums[mid]<nums[l]){
                if(target>=nums[mid]&&target<=nums[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
            else{
                l++;
            }
        }
        return false;
    }
};