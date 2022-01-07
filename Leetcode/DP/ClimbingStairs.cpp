class Solution {
public:
    // vector<int>dp=vector(46,0);
    int climbStairs(int n) {
        //using recursion tle
        // if(n<0) return 0;
        // if(n==0) return 1;
        //if(n==1||n==2) return n;
        // int count =climbStairs(n-1)+climbStairs(n-2);
        // return count;
        //using memo dp
        // if(n<0) return 0;
        // if(n==0) return 1;
        //if(n==1||n==2) return n;
        // if(dp[n]!=0) return dp[n];
        // int count =dp[n]=climbStairs(n-1)+climbStairs(n-2);
        // return count;
        //using top down dp
        // vector<int>dp(n+2);
        // dp[0]=0;dp[1]=1;dp[2]=2;
        // for(int i=3;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        //instead of maintaining the whole table ,we save only last two values,because
        //thats the only two values thats required to get the answer just like fibbonacci
        if(n<0) return 0;
        if(n==0) return 1;
        if(n==1||n==2) return n;
        int a=1,b=2,c;
        for(int i=3;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};