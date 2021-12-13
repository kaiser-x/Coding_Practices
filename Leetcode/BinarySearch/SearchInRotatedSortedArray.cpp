class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            //found then return
            if(nums[mid]==target) return mid;
            //check if left is sorted
            if(nums[mid]>=nums[l]){
                //check if target is in the sorted range
                if(target>=nums[l]&&target<=nums[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            //right is sorted
            else{
                //check if target present in sorted range
                if(target>=nums[mid]&&target<=nums[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
       
        return -1;
    }
};