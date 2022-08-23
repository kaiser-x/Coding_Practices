// 441. Arranging Coins
// Easy
// You have n coins and you want to build a staircase with these coins. 
// The staircase consists of k rows where the ith row has exactly i coins. 
// The last row of the staircase may be incomplete.
// Given the integer n, return the number of complete rows of the staircase you will build.

 
 class Solution {
    /* The idea is simple, we take a mid from 1 to n,then we subtract that mid from given number
    coins,that is the mis level staircase used mid number of coins, then we take sumtillN of
    mid-1 stairs, we check if the remaining number of coins are equal to or greater than the
    required number of coins we found through sum from 0 till mid-1,if this is the case,then 
    that can be our answer or there is answer on higher stairs so we store ans and move 
    low to mid +1, else we move high to mid -1*/
public:
     long long unsigned int sumOfTillN(long long unsigned int n){
        return (n*(n+1))/2;
    }
  int arrangeCoins(int n) {
        int l=1,h=n,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(n-mid>=sumOfTillN(mid-1)) {
                ans=mid;l=mid+1;
            }else h=mid-1;
        }
        return ans;
    }
};

Java  code:

class Solution {
    static long sumOfTillN(long n){
        return (n*(n+1))/2;
    }
  int arrangeCoins(int n) {
        int l=1,h=n,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(n-mid>=sumOfTillN(mid-1)) {
                ans=mid;l=mid+1;
            }else h=mid-1;
        }
        return ans;
    }
}