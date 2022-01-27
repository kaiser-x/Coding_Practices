// 941. Valid Mountain Array
// Easy
// Given an array of integers arr, return true if and only 
// if it is a valid mountain array.

// Recall that arr is a mountain array if and only if:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Example 1:
// Input: arr = [2,1]
// Output: false
// Example 2:

// Input: arr = [3,5,5]
// Output: false
// Example 3:

// Input: arr = [0,3,2,1]
// Output: true

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
      if(n<=2) return false;
      int peek=0;
      // there can only be one peek and if theres a valley pr theres value which is not 
      //strictly inc or dec like arr[i]==arr[i+1] or == arr[i-1] then just return false
      for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) peek++;
        if(arr[i]<=arr[i-1]&&arr[i]<=arr[i+1]) return false;
      }
      return peek==1;
    }
};