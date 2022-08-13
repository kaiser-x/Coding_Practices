// 35. Search Insert Position
// Easy
// Given a sorted array of distinct integers and a target value, 
// return the index if the target is found. If not,
// return the index where it would be if it were inserted in order

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0||target<nums[0]) return 0;
        if(target>nums[n-1]) return n;
        int l=0,h=n-1;
        long long int mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        /*for now why returm mid does not work but return low works,remember we need to send
        the index of targert if found otherwise return where it should have been present
        or inserted,for eg [1,3,5,6], target 2, the first l=1,h=6,m=3, 3>2 so h=m-1,
        now l=1,h=1 and m=1, 1>2 so l=m+1, here h and m are at the same place where as l is 
        moved and points to where 2 can be inserted,now lets take [1,3,4,6] ,t= 5,
        l=1,h=6,m=3, 3<5 so l=m+1,l=4,h=6 and m=4, 4<5,l=m+1,l=6,h=6 and m=6, now at the last
        iteration, h=m-1, h=4 but l is still at 6,similiary if we take target 7, as last 
        iteration l=m+1 and l will be at pointing out of the array,so that will be the
        result, thats why we return l instead of mid or h,*/
        // return mid;
        return l;
    }
};