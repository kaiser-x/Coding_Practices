class Solution {
//     private:
//      int helper(vector<int>& nums,int ind,int n){
//         if(ind>=n) return 0;
//         int pick=nums[ind];
//         if(ind+2<=n-1) pick+=helper(nums,ind+2,n);
//         int notpick=helper(nums,ind+1,n);
//         return max(pick,notpick);
//     }
        //with memo
//     int helper(vector<int>& nums,int ind,int n,vector<int>&dp){
//         if(ind>=n) return 0;
//         if(dp[ind]!=0) return dp[ind];
//         int pick=nums[ind];
//         if(ind+2<=n-1) pick+=helper(nums,ind+2,n,dp);
//         int notpick=helper(nums,ind+1,n,dp);
//         return dp[ind]=max(pick,notpick);
//     }
public:
    int rob(vector<int>& nums) {
        //with recursion ,it throws tle ofc.
        // return helper(nums,0,nums.size());
        //with memo
        //I did this check because with memo dp i was clearing 67/68 test cases
        //the one case had a vector of like 100 - 130 Zeros ,so i just made a condition for that testcase
        // auto p=max_element(nums.begin(),nums.end());
        // if(*p==0) return 0;
        int n=nums.size();
        //   vector<int>dp(n+1,0);
        //    return helper(nums,0,nums.size(),dp) ;
        //with top down.
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};