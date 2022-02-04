// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
// Medium

// Given an array of integers arr and two integers k and threshold, return the number 
// of sub-arrays of size k and average greater than or equal to threshold.
// Example 1:

// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
// Output: 3
// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively.
//  All other sub-arrays of size 3 have averages less than 4 (the threshold).
// Example 2:

// Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
// Output: 6
// Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that 
// averages are not integers.

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int i=0,j=0,count=0;
        int sum=0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1<k) j++;
            else{
                //instead of sum/k>= threshold,just throw the k on rhs
                //sum>=k/*threshold.just slight optimization
                if(sum>=k*threshold) count++;
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
};