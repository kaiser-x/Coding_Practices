class Solution {
    private://without dp
    // int helper(vector<int>&nums,int ind,int n,int f){
    //     if(ind==n-1&&f==1) return 0;
    //     if(ind>=n&&f==0) return 0;
    //     int pick=nums[ind];
    //     if(ind+2<=n-1) pick+=helper(nums,ind+2,n,f);
    //     int notpick=helper(nums,ind+1,n,f);
    //     return max(pick,notpick);
    // }
    //with dp memo
    // int helper(vector<int>&nums,int ind,int n,int f,vector<int>&dp){
    //     if(ind==n-1&&f==1) return 0;
    //     if(ind>=n&&f==0) return 0;
    //     if(dp[ind]!=0) return dp[ind];
    //     int pick=nums[ind];
    //     if(ind+2<=n-1) pick+=helper(nums,ind+2,n,f,dp);
    //     int notpick=helper(nums,ind+1,n,f,dp);
    //     return dp[ind]=max(pick,notpick);
    // }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // if(n==1) return nums[0];
        //with recursion
        // return max(helper(nums,1,n,0),helper(nums,0,n,1));
        // vector<int>dp(n+1,0);
        // vector<int>dp1(n+1,0);
        // return max(helper(nums,1,n,0,dp),helper(nums,0,n,1,dp1));
        //with top down approach
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp(n+1,0);
        vector<int>dp1(n+1,0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(int i=2;i<n-1;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            // cout<<dp[i];
        }
        dp1[1]=nums[1];
        dp1[2]=max(nums[2],dp1[1]);
        for(int i=3;i<n;i++)
            dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
        return max(dp[n-2],dp1[n-1]);
    }
};