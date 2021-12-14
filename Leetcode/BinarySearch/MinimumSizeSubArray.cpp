// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and
//  a positive integer target, return the 
//  minimal length of a contiguous 
//  subarray [numsl, numsl+1, ..., numsr-1, numsr] 
//  of which the sum is greater than or equal to target.
//   If there is no such subarray, return 0 instead.

//Binary Search on answer
class Solution {
    private:
    int maxSubarray(int k,vector<int>&nums){
        int start=0,end=0;
        int max=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(end=0;end<n;end++){
            sum+=nums[end];
            if(end>=k-1){
                if(sum>max) max=sum;
                    sum-=nums[start];
                    start++;
            }
        }
        return max;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=1,h=n+1,f=0;
        while(l<h){
            int mid=l+(h-l)/2;
            int res=maxSubarray(mid,nums);
            // cout<<res<<" ";
            if(res>=target) {
                h=mid;
                f=1;
            }
            else 
                l=mid+1;
        }
        if(f==1) 
            return l;
        return 0;
    }
};

//simple two pointer approach
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            ans = min(ans, i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}