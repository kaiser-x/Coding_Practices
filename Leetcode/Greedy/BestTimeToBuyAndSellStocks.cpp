// 21. Best Time to Buy and Sell Stock
// Easy
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a 
// different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve 
// any profit, return 0.
// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX,mx=INT_MIN,profit=0;
        for(int i:prices){
            mn=min(mn,i);
            profit=i-mn;
            mx=max(mx,profit);
        }
        return mx;
        
//The logic to solve this problem is same as "max subarray problem" using Kadane's Algorithm. Since no body has mentioned this so far, I thought it's a good thing for everybody to know.

// All the straight forward solution should work, but if the interviewer twists the question slightly by giving the difference array of prices, Ex: for {1, 7, 4, 11}, if he gives {0, 6, -3, 7}, you might end up being confused. 

// Here, the logic is to calculate the difference (maxCur += prices[i] - prices[i-1]) of the original array, and find a contiguous subarray giving maximum profit. If the difference falls below 0, reset it to zero.
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};